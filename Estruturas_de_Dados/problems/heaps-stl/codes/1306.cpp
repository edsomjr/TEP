#include <bits/stdc++.h>

using namespace std;

const int MAX { 125002 };

class Heap {
private:
    size_t N;
    unsigned int xs[MAX];

    size_t parent(int i) { return i/2; }
    size_t left(int i) { return 2*i; }
    size_t right(int i) { return 2*i + 1; }

public:
    Heap() : N(0) {}

    size_t size() const { return N; }

    void insert(int x)
    {
        ++N;

        xs[N] = x;

        int i = N, p = parent(i);

        while (p and xs[p] < xs[i])
        {
            std::swap(xs[p], xs[i]);
            i = p;
            p = parent(i);
        }
    }

    unsigned int extract_max()
    {
        auto x = xs[1];
        std::swap(xs[1], xs[N]);
        --N;

        int i = 1, n = left(i) > N ? 0 : left(i);

        while (n)
        {
            auto r = right(i) > N ? 0 : right(i);

            if (r and xs[r] > xs[n])
                n = r;

            if (xs[i] < xs[n])
            {
                std::swap(xs[i], xs[n]);
                i = n;
                n = left(i) > N ? 0 : left(i);
            } else
                n = 0;
        }

        return x;
    }
};

int main()
{
    unsigned int N;
    scanf("%u", &N);

    Heap pq;

    for (size_t i = 0; i < N; ++i)
    {
        unsigned int x;
        scanf("%u", &x);

        pq.insert(x);

        if (pq.size() > N/2 + 1)
            pq.extract_max();
    }

    double ans = pq.extract_max();

    if (N % 2 == 0)
    {
        ans += pq.extract_max();
        ans /= 2.0;
    }

    printf("%.1f\n", ans);

    return 0;
}
