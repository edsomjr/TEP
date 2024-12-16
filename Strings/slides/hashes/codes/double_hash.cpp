#include <iostream>

using namespace std;

int f(char c) { return c - 'a' + 1; }

int hi(long long pi, long long qi, const string& s)
{
    int N = s.size();
    long long ans = 0;

    for (int i = N - 1; i >= 0; --i)
    {
        ans = (ans * pi) % qi;
        ans = (ans + f(s[i])) % qi;
    }

    return ans;
}

pair<int, int> h(const string& s)
{
    constexpr long long p1 = 31, q1 = 1'000'000'007;
    constexpr long long p2 = 29, q2 = 1'000'000'009;

    return { hi(p1, q1, s), hi(p2, q2, s) };
}

int main()
{
    string s;
    cin >> s;

    auto [h1, h2] = h(s);

    cout << "(" << h1 << ", " << h2 << ")\n";

    return 0;
}
