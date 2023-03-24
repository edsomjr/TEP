#include <bits/stdc++.h>

using namespace std;

const int MAX { 10000001 };

bool is_prime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i < n; ++i)
        if (n % i == 0)
            return false;

    return true;
}

bool is_prime2(int n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i < n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

bool is_prime3(int n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

vector<int> primes(int N)
{
    vector<int> ps;

    for (int i = 2; i <= N; ++i)
        if (is_prime3(i))
            ps.push_back(i);

    return ps;
}

vector<int> primes2(int N) {
    vector<int> ps;
    bitset<MAX> sieve;              // MAX deve ser maior do que N
    sieve.set();                    // Todos são "potencialmente" primos
    sieve[1] = false;               // 1 não é primo

    for (int i = 2; i <= N; ++i) {
        if (sieve[i]) {             // i é primo
            ps.push_back(i);

            for (int j = 2 * i; j <= N; j += i)
                sieve[j] = false;
        }
    }

    return ps;
}

vector<int> primes3(int N)
{
    bitset<MAX> sieve;                  // MAX deve ser maior do que N
    vector<int> ps { 2 };               // Os pares são tratados à parte
    sieve.set();                        // Todos são "potencialmente" primos

    for (int i = 3; i <= N; i += 2) {   // Apenas ímpares são verificados agora
        if (sieve[i]) {                 // i é primo
            ps.push_back(i);

            for (int j = 2 * i; j <= N; j += i)
                sieve[j] = false;
        }
    }

    return ps;
}

vector<long long> primes4(long long N)
{
    bitset<MAX> sieve;                  // MAX deve ser maior do que N
    vector<long long> ps { 2 };         // Os pares são tratados à parte
    sieve.set();                        // Todos são "potencialmente" primos

    for (long long i = 3; i <= N; i += 2) {   // Apenas ímpares são verificados agora
        if (sieve[i]) {                       // i é primo
            ps.push_back(i);

            for (long long j = i * i; j <= N; j += 2*i)   // Múltiplos ímpares >= i*i
                sieve[j] = false;
        }
    }

    return ps;
}

vector<long long> primes5(long long N)
{
    bitset<MAX> sieve;              // MAX deve ser maior do que N
    vector<long long> ps { 2, 3 };  // Pares e múltiplos de 3 são tratados à parte
    sieve.set();                    // Todos são "potencialmente" primos

    // O incremento alterna entre saltos de 2 ou 4, evitando os múltiplos de 3
    for (long long i = 5, step = 2; i <= N; i += step, step = 6 - step) {
        if (sieve[i]) {                                   // i é primo
            ps.push_back(i);

            for (long long j = i * i; j <= N; j += 2*i)   // Múltiplos ímpares >= i*i
                sieve[j] = false;
        }
    }
    return ps;
}

int main()
{
    cout << "==== Testes de primalidade:\n\n";

    auto p = 999983;
    auto start = chrono::system_clock::now();
    auto ok = is_prime(p);
    auto end = chrono::system_clock::now();
    chrono::duration<double> t = end - start;

    cout.precision(15);
    cout << fixed;
    cout << "is_prime(" << p << ")  = " << ok << " (" << t.count() << " ms)\n";

    start = chrono::system_clock::now();
    ok = is_prime2(p);
    end = chrono::system_clock::now();
    t = end - start;

    cout << "is_prime2(" << p << ") = " << ok << " (" << t.count() << " ms)\n";

    start = chrono::system_clock::now();
    ok = is_prime3(p);
    end = chrono::system_clock::now();
    t = end - start;

    cout << "is_prime3(" << p << ") = " << ok << " (" << t.count() << " ms)\n";

    cout << "\n\n==== Geração de primos até N:\n\n";
    auto N = 10000000;

    start = chrono::system_clock::now();
    auto ps = primes(N);
    end = chrono::system_clock::now();
    t = end - start;

    cout << "primes(" << N << ")  = " << ps.size() << " (" << t.count() << " ms)\n";

    start = chrono::system_clock::now();
    ps = primes2(N);
    end = chrono::system_clock::now();
    t = end - start;

    cout << "primes2(" << N << ") = " << ps.size() << " (" << t.count() << " ms)\n";

    start = chrono::system_clock::now();
    ps = primes3(N);
    end = chrono::system_clock::now();
    t = end - start;

    cout << "primes3(" << N << ") = " << ps.size() << " (" << t.count() << " ms)\n";

    long long M = N;
    start = chrono::system_clock::now();
    auto qs = primes4(M);
    end = chrono::system_clock::now();
    t = end - start;

    cout << "primes4(" << N << ") = " << qs.size() << " (" << t.count() << " ms)\n";

    start = chrono::system_clock::now();
    qs = primes5(M);
    end = chrono::system_clock::now();
    t = end - start;

    cout << "primes5(" << N << ") = " << qs.size() << " (" << t.count() << " ms)\n";

    return 0;
}
