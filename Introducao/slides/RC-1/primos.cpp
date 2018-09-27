#include <iostream>

bool is_prime(long N) {
    if (N == 2) return true;
    if (N < 2 or not (N & 1)) return false;
        
    for (long d = 3; d * d <= N; d += 2)
        if (not (N % d))
            return false;
            
    return true;
}

int main() {
    long N = 1013;
    
    std::cout << N << (is_prime(N) ? " e " : " nao e ") 
        << "um numero primo" << std::endl;
    
    return 0;
}
