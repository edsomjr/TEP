#include <bits/stdc++.h>

using namespace std;

bool is_solution(int i, int N) { return i == N; }

void process_solution(const vector<int>& xs)
{
    cout << "{ ";

    for (auto x : xs)
        cout << x << ' ';

    cout << "}\n";
}

vector<int> candidates(int i, const vector<int>& as)
{
    return { as[i] };
}

void backtracking(vector<int>& xs, int i, int N, const vector<int>& as)
{
    if (is_solution(i, N))
        process_solution(xs);
    else
    {
        auto cs = candidates(i, as);

        for (auto c : cs)
        {
            // Segue sem escolher c
            backtracking(xs, i + 1, N, as);

            // Segue escolhendo c
            xs.push_back(c);
            backtracking(xs, i + 1, N, as);
            xs.pop_back();
        }
    }
}

int main()
{
    vector<int> as { 2, 3, 5, 7, 11 }, xs;

    backtracking(xs, 0, as.size(), as);

    return 0;
} 
