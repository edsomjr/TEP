#include <iostream>

using namespace std;

int f(char c) { return c - 'a' + 1; }

int hi(long long pi, long long qi, const string& s)
{
    long long ans = 0;

    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        ans = (ans * pi) % qi;
        ans = (ans + f(*it)) % qi;
    }

    return ans;
}

pair<int, int> h(const string& s)
{
    const long long p1 = 31, q1 = 1000000007;
    const long long p2 = 29, q2 = 1000000009;

    return make_pair(hi(p1, q1, s), hi(p2, q2, s));
}

int main()
{
    string s;
    cin >> s;

    auto hs = h(s);

    cout << "(" << hs.first << ", " << hs.second << ")\n";

    return 0;
}
