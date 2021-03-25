vector<int> solve(int N)
{
    auto ps = primes5(55555);

    vector<int> qs;
    int k = 2;          // Escolha arbitrária: qualquer valor em [1, 4] é válido

    for (auto p : ps)
        if (p % k == 0)
            qs.push_back(p);

    vector<int> ans(qs.begin(), qs.begin() + N);
 
    return ans;
}
