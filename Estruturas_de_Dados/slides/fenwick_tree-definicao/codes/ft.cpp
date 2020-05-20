#include <bits/stdc++.h>

using namespace std;

template<typename T>
class BITree {
private:
    vector<T> ts;
    size_t N;

public:
    BITree(size_t n) : ts(n + 1, 0), N(n) {}

    T RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

private:
    int LSB(int n) { return n & (-n); }

    T RSQ(int i)
    {
        T sum = 0;

        while (i >= 1)
        {
            sum += ts[i];
            i -= LSB(i);
        }

        return sum;
    }

public:
    void add(size_t i, const T& x)
    {
        if (i == 0)
            return;

        while (i <= N)
        {
            ts[i] += x;
            i += LSB(i);
        }
    }
};

int main()
{
    BITree<int> ft(8);
    vector<int> xs { 0, 2, 0, 1, 3, -1, 5, -2, 4 };

    for (size_t i = 1; i <= 8; ++i)
        ft.add(i, xs[i]);

    cout << ft.RSQ(3, 7) << '\n';
    
    return 0;
}
