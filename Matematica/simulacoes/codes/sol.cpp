long long solve(long long N)
{
    long long m = (-1 + sqrt(1 + 8*m))/2;

    return (m + 1)*(m + 2)/2 <= N ? m + 1 : m;
}

