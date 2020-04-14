vector<pair<int, int>> prod(const vector<int>& A, const vector<int>& B)
{
    vector<pair<int, int>> P;
    int n = A.size(), m = B.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
                P.push_back(make_pair(A[i], B[j]));

    return P;
}
