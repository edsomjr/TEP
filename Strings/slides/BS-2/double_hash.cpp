#include <iostream>

using namespace std;

int f(char c)
{
    return c - 'a' + 1;
}

int hi(long long pi, long long mi, const string& s)
{
    long long ans = 0;

    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        ans = (ans * pi) % mi;
        ans = (ans + f(*it)) % mi;
    }

    return ans;
}

pair<int, int> h(const string& s)
{
    const long long p1 = 31, m1 = 1000000007;
    const long long p2 = 29, m2 = 1000000009;

    return make_pair(hi(p1, m1, s), hi(p2, m2, s));
}

int main()
{
    string s;
    cin >> s;

    auto hs = h(s);

    cout << "(" << hs.first << ", " << hs.second << ")\n";

    return 0;
}
