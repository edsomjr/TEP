#include <bits/stdc++.h>

using namespace std;

vector<int> borders(const string& pat)
{
    int m = pat.size();
    int t = -1;     // t = |border(pat[0..(j - 1)])|

    vector<int> bord(m + 1);
    bord[0] = -1;

    for (int j = 0; j < m; ++j)
    {
        while (t > -1 and pat[t] != pat[j])
            t = bord[t];

        bord[j + 1] = ++t;
    }

    return bord;
}

int MP(const string& text, const string& pat)
{
    int n = text.size();
    int m = pat.size();
    int i = 0, j = 0, occ = 0;

    vector<int> bords = borders(pat);

    while (i <= n - m)
    {
cout << "comparison between '" << text.substr(i) << "' and '" << pat << "'\n";
        while (j < m and pat[j] == text[i + j])
            ++j;

cout << "mismatch on char " << pat[j] << ", pos = " << j << '\n';
        if (j == m)
        {
cout << "match on position " << i << ": " << text.substr(i, m) << '\n';
            ++occ;
        }

        int MP_shift = j - bords[j];
        i += MP_shift;
        j = max(0, j - MP_shift);
cout << "shift = " << MP_shift << ", new i = " << i << ", j = " << j << '\n';
    } 

    return occ;
}

int main()
{
    string s = "abcabdabcdabcabc", pat = "ababbababab";
    auto bs = borders(pat);

    cout << "i\tsubs\t\tborder\tshift\n";

    for (size_t i = 0; i <= pat.size(); ++i)
    {
        cout << i << '\t' << pat.substr(0, i) << '\t';

        if (i < 8)
            cout << '\t';

        cout << bs[i] << '\t' << i - bs[i] << '\n';
    }

    cout << MP(s, pat) << '\n';
    return 0;
}
