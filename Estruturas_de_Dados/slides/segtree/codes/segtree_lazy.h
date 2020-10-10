#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

template<typename T>
class SegmentTree
{
private:
    int N;
    std::vector<T> ns, lazy;

public:
    SegmentTree(const std::vector<int>& xs)
        : N(xs.size()), ns(4*N), lazy(4*N, 0)
    {
        for (size_t i = 0; i < xs.size(); ++i)
            update(i, i, xs[i]);
    }

    void update(int a, int b, T value)
    {
        update(1, 0, N - 1, a, b, value);
    }

private:
    void update(int node, int L, int R, int a, int b, T value)
    {
        // Lazy propagation
        if (lazy[node])
        {
            ns[node] += (R - L + 1) * lazy[node];

            if (L < R)      // Se o nó não é uma folha, propaga
            {
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        // [a, b] ∩ [L, R] = {∅}
        if (a > R or b < L)
            return;

        // [L, R] ⊂ [a, b] está contido; é subconjunto de
        if (a <= L and R <= b)
        {
            ns[node] += (R - L + 1) * value;

            if (L < R)
            {
                lazy[2*node] += value;
                lazy[2*node + 1] += value;
            }

            return;
        }
 
        update(2*node, L, (L + R)/2, a, b, value);
        update(2*node + 1, (L + R)/2 + 1, R, a, b, value);

        ns[node] = ns[2*node] + ns[2*node + 1];
    } 

public:
    T RSQ(int a, int b)
    {
        return RSQ(1, 0, N - 1, a, b);
    }

private:
    T RSQ(int node, int L, int R, int a, int b)
    {
        if (lazy[node])
        {
            ns[node] += (R - L + 1) * lazy[node];

            if (L < R)
            {
                lazy[2*node] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (a > R or b < L)
            return 0;

        if (a <= L and R <= b)
            return ns[node];

        T x = RSQ(2*node, L, (L + R)/2, a, b);
        T y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return x + y;
    }
};

#endif
