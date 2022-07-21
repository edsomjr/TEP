#include <bits/stdc++.h>

using namespace std;

vector<int> suffix_array(const string& s)
{
    using si = pair<string, int>;

    vector<si> ss(s.size());

    for (size_t i = 0; i < s.size(); ++i)
        ss[i] = si(s.substr(i), i);

    sort(ss.begin(), ss.end());

    vector<int> sa(s.size());

    for (size_t i = 0; i < s.size(); ++i)
        sa[i] = ss[i].second;

    return sa;
}

int main()
{
    string s;
    cin >> s;

    auto sa = suffix_array(s);

    for (size_t i = 0; i < s.size(); ++i)
        cout << sa[i] << '\t' << s.substr(sa[i]) << '\n';

    return 0;
}
