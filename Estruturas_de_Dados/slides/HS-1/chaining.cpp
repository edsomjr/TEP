#include <bits/stdc++.h>

using namespace std;

template<typename I, size_t T>
class HashSet {
private:
    size_t mod(const I& a, int b) { return ((a % b) + b) % b; }

    size_t h(const I& K) { return mod(K, T); }

    vector<list<I>> xs;

public:
    HashSet() : xs(T) {}

    void insert(const I& K)
    {
        xs[h(K)].push_back(K);
    }

    friend ostream& operator<<(ostream& os, const HashSet& hs)
    {
        os << "xs = ";

        for (const auto ys : hs.xs)
        {
            os << "[ ";
    
            for (const auto y : ys)
                os << y << " ";

            os << "] ";
        }

        os << '\n';

        return os;
    }
}; 

int main()
{
    vector<int> ks { 51, 16, 76, 35, -6, 49 };
    HashSet<int, 11> hs;

    for (const auto& k : ks)
    {
        hs.insert(k);
        cout << hs << '\n';
    }

    return 0;
}
