#include <bits/stdc++.h>

using namespace std;

int main()
{
    string text { "cesar cipher xyz" };
    string cipher;

    transform(text.begin(), text.end(), back_inserter(cipher),
        [](char c) {
            return c == ' ' ? c : (((c - 'a') + 3) % 26) + 'a';
        }
    );

    cout << cipher << endl;

    return 0;
}
