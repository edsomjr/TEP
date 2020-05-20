template<typename T>
long long count_inversions_compression(const vector<T>& as)
{
    set<T> xs(as.begin(), as.end());
    map<T, int> f;
    size_t N = 0;

    for (const auto& x : xs)
        f[x] = ++N;

    BITree<T> ft(N);
    long long inversions = 0;

    for (const auto& a : as)
    {
        inversions += ft.RSQ(f[a] + 1, N);
        ft.add(f[a], 1);
    }

    return inversions;
}
