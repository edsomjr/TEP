template<typename T>
long long count_inversions(const vector<T>& as, int N, int M)
{
    long long inversions = 0;
    BITree<T> ft(M);

    for (int i = 1; i <= N; ++i)
    {
        inversions += ft.RSQ(as[i] + 1, M);
        ft.add(as[i], 1);
    }

    return inversions;
}
