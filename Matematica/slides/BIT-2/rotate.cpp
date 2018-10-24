#include <bits/stdc++.h>

using namespace std;

unsigned long rotate_right(unsigned long n, int k)
{
    unsigned long left = (n >> k);
    unsigned right = n & ((1 << k) - 1);

    return right << (8*sizeof(unsigned long) - k) | left;
}

int main() {
    unsigned long n = 0x12345678;

    printf("0x%08lx\n", rotate_right(n, 8));  // 0x78123456
    printf("0x%08lx\n", rotate_right(n, 16)); // 0x56781234
    printf("0x%08lx\n", rotate_right(n, 3));  // 0x02468acf

    return 0;
}
