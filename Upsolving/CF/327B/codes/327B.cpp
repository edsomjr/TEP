vector<int> solve(int N)
{
    // A função sieve() retorna números primos menores ou iguais ao
    // argumento passado, identificados por meio do crivo de Erastótenes
    auto ps = sieve(10000000);      

    vector<int> ans(ps.begin(), ps.begin() + N);

    return ans;
}
