template<typename T>
class BITree2D {
public:
    vector<vector<T>> ft;
    int N;

    BITree2D(size_t n) : ft(n + 1, vector<T>(n + 1, 0)), N(n) {}

    // Range query
    T RSQ(int a, int b, int c, int d) {
        return RSQ(c, d) - RSQ(c, b-1) - RSQ(a-1, d) + RSQ(a-1, b-1);
    }

    // Point update
    void add(int x, int y, T v)
    {
        for (int i = x; i <= N; i += LSB(i))
            for (int j = y; j <= N; j += LSB(j))
                ft[i][j] += v;
    }

private:
    int LSB(int n) { return n & -n; }

    T RSQ(int a, int b)
    {
        int sum = 0;
        
        for (int i = a; i > 0; i -= LSB(i))
            for (int j = b; j > 0; j -= LSB(j))
                sum += ft[i][j];

        return sum;
    }
};
