#include <stdio.h>

union word32 {
    unsigned int value;
    unsigned char byte[4];
};

int main()
{
    union word32 word, rotate;
    register unsigned int i;

    word.value = 0x12345678;

    for (i = 0; i < 4; i++)
        rotate.byte[i] = word.byte[(i+1) % 4];

    printf("word: %08x, rotate: %08x\n", word.value, rotate.value);

    return 0;
}
