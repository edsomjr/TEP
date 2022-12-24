#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

template<typename T>
class SegmentTree
{
    int N;
    std::vector<T> ns;

public:
    SegmentTree(const std::vector<int>& xs) : N(xs.size()), ns(4*N, 0)
    {
        for (size_t i = 0; i < xs.size(); ++i)
            update(i, xs[i]);
    }

    void update(int i, T value)
    {
        update(1, 0, N - 1, i, value);
    }

private:
    void update(int node, int L, int R, int i, T value) {   
        // Caso base: i não pertence ao intervalo [L, R]
        if (i > R or i < L)
            return;
        
        ns[node] += value;

        // Caso base: node é uma folha
        if (L == R)
            return;

        update(2*node, L, (L+R)/2, i, value);
        update(2*node + 1, (L+R)/2 + 1, R, i, value);
    } 

public:
    T RSQ(int a, int b)
    {
        return RSQ(1, 0, N - 1, a, b);
    }

private:
    T RSQ(int node, int L, int R, int a, int b)
    {
        if (a > R or b < L)         // [a, b] ∩ [L, R] = {∅}
            return 0;

        if (a <= L and R <= b)      // [L, R] ⊂ [a, b] 
            return ns[node];

        T x = RSQ(2*node, L, (L + R)/2, a, b);
        T y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return x + y;
    }

};

#endif
