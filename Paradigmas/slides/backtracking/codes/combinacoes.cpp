#include <bits/stdc++.h>

using namespace std;

bool is_solution(const vector<int>& xs, size_t M)
{
    return xs.size() == M;
}

void process_solution(const vector<int>& xs, const vector<int>& as)
{
    cout << "(";

    for (size_t i = 0; i < xs.size(); ++i)
        cout << as[xs[i]] << (i + 1 == xs.size() ? ")\n" : ", ");
}

vector<int> candidates(const vector<int>& xs, const vector<int>& as)
{
    vector<int> cs;

    if (xs.empty())
    {
        cs.resize(as.size());
        iota(cs.begin(), cs.end(), 0);
    } else
        for (size_t i = xs.back() + 1; i < as.size(); ++i)
            cs.push_back(i);

    return cs;
}

void backtracking(vector<int>& xs, size_t M, const vector<int>& as)
{
    if (is_solution(xs, M))
        process_solution(xs, as);
    else
    {
        auto cs = candidates(xs, as);

        for (auto c : cs)
        {
            xs.push_back(c);
            backtracking(xs, M, as);
            xs.pop_back();
        }
    }
}

int main()
{
    vector<int> as { 1, 2, 5, 10, 25, 50, 100 }, xs;

    backtracking(xs, 4, as);

    return 0;
}
