#include <bits/stdc++.h>

using namespace std;

auto max_ordered_substring(const string& s)
{
    auto N = s.size(), L = 0ul, ans = 0ul;

    while (L < N) {
        auto R = L + 1;

        while (R < N and s[R - 1] <= s[R])
            ++R;

        ans = max(ans, R - L);
        L = R;
    }

    return ans;
}

int main()
{
    string s1 { "abcde" }, s2 { "cba" }, s3 { "teste" };

    cout << max_ordered_substring(s1) << '\n';
    cout << max_ordered_substring(s2) << '\n';
    cout << max_ordered_substring(s3) << '\n';

    return 0;
}
