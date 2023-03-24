polynomial operator*(const polynomial& p, const polynomial& q)
{
    int N = degree(p), M = degree(q);
    polynomial r(N + M + 1, 0);

    for (int i = 0; i <= N; ++i)
        for (int j = 0; j <= M; ++j)
            r[i + j] += p[i]*q[j];

    return r;
}
