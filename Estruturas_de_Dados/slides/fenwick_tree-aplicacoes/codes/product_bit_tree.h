template<typename T>
class BITree
{
private:
    T N;
    vector<T> ft, zs;                                       // zi = 1 se ai = 0

    T LSB(const T& n) { return n & -n; }
 
public:
    BITree(int n) : N(n), ft(N + 1, 1), zs(N + 1, 0) { }

    T RPQ(int i, int j)
    {
        auto p = RPQ(j) / RPQ(i - 1);
        auto z = RSQ(i, j);

        return z ? 0 : p;
    }

    void update(int i, const T& v)
    {
        if (v)
            multiply(i, v);
        else if (RSQ(i, i) == 0)
            add(i, 1);
    }
    
private:
    int RPQ(int i)
    {
        int prod = 1;

        while (i) {
            prod *= ft[i];
            i -= LSB(i);
        }

        return prod;
    }

    int RSQ(int i, int j)
    {
        return RSQ(j) - RSQ(i - 1);
    }

    int RSQ(int i)
    {
        int sum = 0;

        while (i)
        {
            sum += zs[i];
            i -= LSB(i);
        }

        return sum;
    }

    void multiply(int i, int v)
    {
        while (i <= N)
        {
            ft[i] *= v;
            i += LSB(i);
        }
    }

    void add(int i, int v)
    {
        while (i <= N)
        {
            zs[i] += v;
            i += LSB(i);
        }
    }
};
