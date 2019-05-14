template<typename T>
long long count_inversions(const vector<T>& as)
{
    T _max = *max_element(as.begin(), as.end());
    BITree<T> ft(_max);
    
    long long inversions = 0;
    for (size_t i = 0; i < as.size(); ++i)
    {
        inversions += ft.RSQ(as[i], _max);
        ft.add(as[i], 1);
    }

    return inversions;
}