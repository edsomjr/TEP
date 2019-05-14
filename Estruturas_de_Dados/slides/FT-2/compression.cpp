template<typename T>
long long count_inversions_compression(const vector<T>& as)
{
    vector<T> xs(as);

    sort(xs.begin(), xs.end());

    map<T, int> f;

    for (size_t i = 1; i <= as.size(); ++i)
        f[ xs[i-1] ] = i;

    BITree<T> ft(as.size());

    long long inversions = 0;

    for(size_t i=0; i<as.size(); i++)
    {
        auto comp_val = f[as[i]];

        inversions += ft.RSQ(comp_val+1, as.size());
        ft.add(comp_val, 1);
    }

    return inversions;
}