#include <bits/stdc++.h>

using namespace std;
using dict = unordered_map<string, string>;

vector<vector<string>> solve(const dict& x, const dict& y)
{
    vector<string> added, removed, changed;

    for (const auto& p : x)
    {
        auto k = p.first;
        auto v = p.second;

        if (y.count(k) == 0)
            removed.push_back(k);
        else if (y.count(k) == 1 and v != y.at(k))
            changed.push_back(k);
    }

    for (const auto& p : y)
    {
        auto k = p.first;

        if (x.count(k) == 0)
            added.push_back(k);
    }

    return { added, removed, changed };
}

dict read_dict(const string& line)
{
    string info = line.substr(1);
    info.pop_back();

    istringstream is(info);
    string key, value;
    
    dict d;

    while (getline(is, key, ':'), getline(is, value, ','))
        d[key] = value;

    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    string line;

    getline(cin, line);
    int T = stoi(line);

    while (T--)
    {
        getline(cin, line);    
        auto x = read_dict(line);

        getline(cin, line);    
        auto y = read_dict(line);

        auto ans = solve(x, y);

        if (x == y)
            cout << "No changes\n";
        else
        {
            const string prefix { "+-*" };

            for (int i = 0; i < 3; ++i)
            {
                if (ans[i].empty())
                    continue;

                sort(ans[i].begin(), ans[i].end());

                cout << prefix[i];

                auto N = ans[i].size();

                for (size_t j = 0; j < N; ++j)
                    cout << ans[i][j] << (j + 1 == N ? '\n' : ',');
            }
        }

        cout << '\n';
    }

    return 0;
}
