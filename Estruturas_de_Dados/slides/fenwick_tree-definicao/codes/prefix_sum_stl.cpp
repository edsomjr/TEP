// Nessa implementação os índices do vetor as vão de 0 a N - 1
template<typename T>
vector<T> prefix_sum(const vector<T>& as)
{
    vector<T> ps(as.size() + 1, 0);

    partial_sum(as.begin(), as.end(), ps.begin() + 1);

    return ps;
}

template<typename T>
T RSQ(const vector<T>& ps, int i, int j)
{
    return ps[j] - ps[i - 1];
}
