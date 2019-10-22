#include <bits/stdc++.h>

using namespace std;

template<typename I, size_t T>
class HashSet {
private:
    size_t mod(const I& a, int b) { return ((a % b) + b) % b; }

    size_t h(const I& K) { return mod(a*K + b, p); }

    size_t N(const I& K, size_t i) { return mod(h(K) + i, T); }

    vector<I> xs;
    I p, a, b;
    bitset<T> used;

public:
    HashSet(const I& pv) : xs(T), p(pv), a(rand() % (p - 1) + 1), 
        b(rand() % p) 
    {}

    bool insert(const I& K)
    {
       if (used.count() == T)
            return false;

        for (size_t i = 0; i < T; ++i)
        {
            auto pos = N(K, i);

            if (not used[pos])
            {
                xs[pos] = K;
                used[pos] = true;
                break;
            }
        }

        return true;
    }

    friend ostream& operator<<(ostream& os, const HashSet& hs)
    {
        os << "h(" << hs.a << ", " << hs.b << ") = [ ";

        for (size_t i = 0; i < T; ++i)
            if (hs.used[i])
                os << hs.xs[i] << " ";
            else
                os  << "-- ";

        os << "]";

        return os;
    }
}; 

int main()
{
    srand(time(NULL));

    vector<int> ks { 33, 17, 95, 27, 88, 15, 54, 62, 40 };
    HashSet<int, 20> hs(101);

    for (const auto& k : ks)
    {
        hs.insert(k);
        cout << hs << '\n';
    }

    return 0;
}
