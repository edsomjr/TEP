#include <bits/stdc++.h>

unsigned long rotate_right(unsigned long n, int k)
{
    unsigned long R = (n >> k);
    unsigned long L = n & ((1 << k) - 1);

    return L << (8*sizeof(unsigned long) - k) | R;
}

int main()
{
    unsigned long n = 0x12345678;

    printf("0x%08lx\n", rotate_right(n, 8));  // 0x78123456
    printf("0x%08lx\n", rotate_right(n, 16)); // 0x56781234
    printf("0x%08lx\n", rotate_right(n, 3));  // 0x02468acf

    return 0;
}
