// NEPS 235 - Telefone (P1) (https://neps.academy/br/exercise/235)
#include <bits/stdc++.h>

using namespace std;

auto solve(string& s)
{
    auto keyboard = "22233344455566677778889999";

    transform(s.begin(), s.end(), s.begin(), [&](char c) { return isalpha(c) ? keyboard[c - 'A'] : c; });

    return s;
}
    
int main()
{
    string s;
    cin >> s;

    cout << solve(s) << '\n';

    return 0;
}
