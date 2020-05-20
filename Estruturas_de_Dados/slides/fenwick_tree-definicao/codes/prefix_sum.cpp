// Os elementos as tem índices de 1 a N
template<typename T>
vector<T> prefix_sum(const vector<T>& as, int N)
{
    vector<T> ps(N + 1, 0);

    for (size_t i = 1; i <= N; ++i)
        ps[i] = ps[i - 1] + as[i];

    return ps;
}

template<typename T>
T RSQ(const vector<T>& ps, int i, int j)
{
    return ps[j] - ps[i - 1];
}
