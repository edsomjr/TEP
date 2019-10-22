#include <iostream>

using namespace std;

int main()
{
    string S { "exemplo" }, P { "abcde" }, Q { "xyz" };

    auto x = S.find_first_of(P);        // x = 0
    x = S.find_first_not_of(P);         // x = 1
    x = S.find_last_of(P);              // x = 2
    x = S.find_last_not_of(P);          // x = 6

    auto y = S.find_first_of(Q);        // y = 1
    y = S.find_first_not_of(Q);         // y = 0
    y = S.find_last_of(Q);              // y = 1
    y = S.find_last_not_of(Q);          // y = 6

    return 0;
}
