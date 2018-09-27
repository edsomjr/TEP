#include "primes.h"
#include <math.h>

int is_prime(long N) {
    long limit, d;

    if (N == 2)
        return 1;
    
    if (N <= 0|| !(N & 0x01))
        return 0;
    
    limit = sqrt(N);
    
    for (d = 3; d <= limit; d++) {
        if (!(N % d))
            return 0;
    }
    
    return 1;
}
