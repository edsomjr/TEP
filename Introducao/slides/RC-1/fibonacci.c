#include <stdio.h>

long nextFibonacci() {
    static long prev = 0;
    static long next = 1;

    long temp = prev + next;
    prev = next;
    next = temp;
    
    return prev;
}

int main() {
    long N = 1000000, next;
    
    while ((next = nextFibonacci()) < N)
        printf("%ld\n", next);
        
    return 0;
}
