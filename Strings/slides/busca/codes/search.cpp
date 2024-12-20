int occurrences(const string& P, const string& S)
{
    int m = P.size();
    int n = S.size();
    int occ = 0;

    for (int i = 0; i < n - m + 1; ++i) 
        occ += (P == S.substr(i, m) ? 1 : 0);

    return occ;
}
