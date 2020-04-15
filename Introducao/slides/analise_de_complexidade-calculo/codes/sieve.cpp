vector<int> sieve(int N)
{
    vector<int> v(N + 1, 1);
    v[0] = v[1] = 0;

    for (int i = 2; i <= N; ++i)
        if (v[i])
            for (int j = 2*i; j <= N; j += i)
                v[j] = 0;
    
    return v;
}
