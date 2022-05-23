#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s { "banana" };
    int number = 0;

    sort(s.begin(), s.end());

    do {
        printf("%02d. %s\n", ++number, s.c_str());
    } while (next_permutation(s.begin(), s.end()));
 
    printf("%s has %d anagrams\n", s.c_str(), number);

    return 0;
}
