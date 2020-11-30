#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c;
    cin >> c;

    string vowels { "aeiou" };

    auto ans = vowels.find(c) == string::npos ? 
        "consonant" : "vowel";

    cout << ans << '\n';

    return 0;
}
