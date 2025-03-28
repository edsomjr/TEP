#include <bits/stdc++.h>

using namespace std;

const int MAX { 20 };

bool is_solution(const vector<int>& xs, const vector<int>& as)
{
    return xs.size() == as.size();
}

void process_solution(const vector<int>& xs, const vector<int>& as)
{
    cout << "(";

    for (size_t i = 0; i < xs.size(); ++i)
        cout << as[xs[i]] << (i + 1 == xs.size() ? ")\n" : ", ");
}

vector<int> candidates(const vector<int>& xs, const vector<int>& as)
{
    bitset<MAX> used;
    vector<int> cs;

    for (auto x : xs)
        used[x] = true;

    for (size_t i = 0; i < as.size(); ++i)
        if (not used[i])
            cs.emplace_back((int) i);

    return cs;
}

void backtracking(vector<int>& xs, const vector<int>& as)
{
    if (is_solution(xs, as))
        process_solution(xs, as);
    else
    {
        auto cs = candidates(xs, as);

        for (auto c : cs)
        {
            xs.emplace_back(c);
            backtracking(xs, as);
            xs.pop_back();
        }
    }
}

int main()
{
    vector<int> as { 1, 2, 3, 4 }, xs;

    backtracking(xs, as);

    return 0;
}
