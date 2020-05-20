template<typename T>
long long count_inversions(const vector<T>& as)
{
    T M = *max_element(as.begin(), as.end());
    BITree<T> ft(M);
    
    long long inversions = 0;

    for (size_t i = 0; i < as.size(); ++i)
    {
        inversions += ft.RSQ(as[i] + 1, M);
        ft.add(as[i], 1);
    }

    return inversions;
}
