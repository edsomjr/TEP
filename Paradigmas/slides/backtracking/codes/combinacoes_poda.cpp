#include <bits/stdc++.h>

using namespace std;

int calls, solutions;

bool is_solution(const vector<int>& xs, size_t M)
{
    return xs.size() == M;
}

void process_solution(const vector<int>&, const vector<int>&)
{
    ++solutions;
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

void backtracking(vector<int>& xs, size_t M, const vector<int>& as,
    bool prunning = false)
{
    ++calls;

    if (is_solution(xs, M))
        process_solution(xs, as);
    else
    {
        auto cs = candidates(xs, as);

        // Não há elementos o suficiente para construir uma solução
        if (prunning and xs.size() + cs.size() < M)
            return;

        for (auto c : cs)
        {
            xs.push_back(c);
            backtracking(xs, M, as, prunning);
            xs.pop_back();
        }
    }
}

int main()
{
    vector<int> as { 1, 2, 5, 10, 25, 50, 100, 200, 500, 10000 }, xs;

    calls = solutions = 0;
    backtracking(xs, 8, as, false);

    cout << "Sem poda -- calls: " << calls
         << ", solutions: " << solutions << '\n';

    calls = solutions = 0;
    xs.clear();
    backtracking(xs, 8, as, true);

    cout << "Com poda -- calls: " << calls
         << ", solutions: " << solutions << '\n';

    // Saída:
    // Sem poda -- calls: 1013, solutions: 45
    // Com poda -- calls: 375, solutions: 45

    return 0;
}
