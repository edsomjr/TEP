#include <bits/stdc++.h>

using namespace std;
using interval = pair<int, int>;

vector<int> max_intersection(const vector<interval>& is)
{
    using event = pair<int, int>;

    vector<event> es;

    for (size_t i = 0; i < is.size(); ++i)
    {
        auto [a, b] = is[i];

        es.emplace_back(a, i + 1);      // Evento de início
        es.emplace_back(b, -(i + 1));   // Evento de fim
    }

    sort(es.begin(), es.end());

    set<int> active, max_set;

    for (const auto& [_, i] : es)
    {
        if (active.size() >= max_set.size())
            max_set = active;

        if (i > 0)
            active.emplace(i);
        else
            active.erase(-i);
    }

    return { max_set.begin(), max_set.end() };
}

int main()
{
    vector<interval> is { { 2, 5 }, { 1, 6 }, { 5, 8 }, { 3, 7 }, 
        { 4, 5 }, { 1, 4 }, { 4, 10 }, { 3, 4 }, { 7, 9 } };

    for (size_t i = 0; i < is.size(); ++i)
        cout << i + 1 << ": (" << is[i].first << ", " 
            << is[i].second << ")\n";

    auto S = max_intersection(is);

    for (size_t i = 0; i < S.size(); ++i)
        cout << S[i] << (i + 1 == S.size() ? '\n' : ' ');

    return 0;
}
