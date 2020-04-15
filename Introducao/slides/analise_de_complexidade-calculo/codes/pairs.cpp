vector<pair<int, int>> pairs(int N)
{
    vector<pair<int, int>> ps;

    for (int a = 1; a <= N; ++a)
        for (int b = a + 1; b <= N; ++b)
            ps.push_back(make_pair(a, b));

    return ps;
}

