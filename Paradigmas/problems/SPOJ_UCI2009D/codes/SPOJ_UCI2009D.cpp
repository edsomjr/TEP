#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

set<set<ii>> solutions;
vector<string> A;

bool is_solution(const vector<ii>& xs)
{
    return xs.size() == 8ul;
}

void process_solution(const vector<ii>& xs)
{
    set<ii> s(xs.begin(), xs.end());
    solutions.emplace(s);
}

vector<ii> candidates(const vector<ii>& xs)
{
    const vector<ii> dirs { ii(0, 1), ii(1, 0), ii(0, -1), ii(-1, 0) };
    set<ii> used(xs.begin(), xs.end());
    vector<ii> cs;

    auto p = xs.back();

    for (auto dir : dirs)
    {
        auto x = p.first + dir.first, y = p.second + dir.second;

        if (A[x][y] == 'X' and used.count(ii(x, y)) == 0)
            cs.push_back(ii(x, y));
    }

    return cs;
}

void backtracking(vector<ii>& xs)
{
    if (is_solution(xs))
    {
        process_solution(xs);
    } else
    {
        auto cs = candidates(xs);

        for (auto c : cs)
        {
            xs.push_back(c);
            backtracking(xs);
            xs.pop_back();
        }
    }
}

size_t solve(int N)
{
    solutions.clear();
    vector<ii> xs;

    for (int x = 1; x <= N; ++x)
        for (int y = 1; y <= N; ++y)
        {
            if (A[x][y] != 'X')
                continue;

            xs.push_back(ii(x, y));
            backtracking(xs);
            xs.pop_back();
        }

    return solutions.size();
}

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        A = vector<string>(N + 2, string(N + 2, ' '));

        for (int i = 1; i <= N; ++i)
        {
            string line;
            cin >> line;

            for (int j = 1; j <= N; ++j)
                A[i][j] = line[j - 1];
        }

        cout << solve(N) << endl;
    }

    return 0;
}
