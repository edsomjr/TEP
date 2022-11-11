#include <bits/stdc++.h>

int main()
{
    unsigned char a = 46;         //  46 = 00101110
    unsigned char b = 151;        // 150 = 10010111

    unsigned char c = a & b;      //   6 = 00000110
    unsigned char d = a | b;      // 191 = 10111111
    unsigned char e = a ^ b;      // 185 = 10111001
    unsigned char f = ~a;         // 209 = 11010001
    unsigned char g = ~b;         // 104 = 01101000

    return 0;
}
