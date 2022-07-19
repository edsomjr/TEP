#include <bits/stdc++.h>

using namespace std;

const int MAX_M { 1000 }, MAX_N { 1000 }, oo { 1000000000 };

int st[MAX_M + 1][MAX_N + 1], ps[MAX_M + 1][MAX_N + 1];

// -        Deletion
// c        Insertion of char c
// =        Keep
// [c->d]   Change (c to d)
string edit_operations(const string& s, const string& t)
{
    const int c_i = 0, c_r = 0, c_s = 1;      // Custos modificados
    int m = s.size(), n = t.size();

    for (int i = 0; i <= m; ++i)
    {
        st[i][0] = i*c_r;
        ps[i][0] = 'r';
    }

    for (int j = 1; j <= n; ++j)
    {
        st[0][j] = j*c_i;
        ps[0][j] = 'i';
    }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            int insertion = st[i][j - 1] + c_i;
            int deletion = st[i-1][j] + c_r;
            int change = st[i-1][j-1] + c_s*(s[i-1] == t[j-1] ? 1 : -oo);
            st[i][j] = max({ insertion, deletion, change });

            ps[i][j] = (insertion >= deletion and insertion >= change) ?
                'i' : (deletion >= change ? 'r' : 's');
        }

    int i = m, j = n;
    ostringstream os;

    while (i or j)
    {
        switch (ps[i][j]) {
        case 'i':
            os << t[j - 1];
            --j;
            break;

        case 'r':
            os << '-';
            --i;
            break;

        case 's':
            if (s[i-1] == t[j-1])
                os << '=';
            else
                os << "]" << t[j - 1] << ">-" << s[i - 1] << "[";

            --i;
            --j;
        }
    }

    auto ops = os.str();
    reverse(ops.begin(), ops.end());

    return ops;
}

string LCS(const string& s, const string& t)
{
    const int c_i = 0, c_r = 0, c_s = 1;      // Custos modificados
    int m = s.size(), n = t.size();

    for (int i = 0; i <= m; ++i) {
        st[i][0] = i*c_r;
        ps[i][0] = 'r';
    }

    for (int j = 1; j <= n; ++j) {
        st[0][j] = j*c_i;
        ps[0][j] = 'i';
    }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            int insertion = st[i][j - 1] + c_i, deletion = st[i - 1][j] + c_r;
            int change = st[i - 1][j - 1] + c_s*(s[i - 1] == t[j - 1] ? 1 : -oo);
            st[i][j] = max({ insertion, deletion, change });

            ps[i][j] = (insertion >= deletion and insertion >= change) ?
                'i' : (deletion >= change ? 'r' : 's');
        }

    int i = m, j = n;
    string b;

    while (i or j) {
        switch (ps[i][j]) {
        case 'i':
            --j;
            break;

        case 'r':
            --i;
            break;

        case 's':
            if (s[i - 1] == t[j - 1])
                b.push_back(s[i - 1]);

            --i;
            --j;
        }
    }

    reverse(b.begin(), b.end());

    return b;
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << s << " -> " << t << ": " << edit_operations(s, t) << '\n';
    cout << "LCS: " << LCS(s, t) << '\n';

    return 0;
}
