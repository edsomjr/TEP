template<typename T>
map<T, int> compression(const vector<T>& as, int N)
{
    vector<T> xs(as);

    sort(xs.begin(), xs.end());

    map<T, int> f;

    for (int i = 1; i <= N; ++i)
        f[xs[i]] = i;

    return f;
} 
