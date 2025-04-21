int binary_search(int x, const vector<int>& xs)
{
    auto a = 0ul, b = xs.size() - 1;

    while (a <= b)
    {
        auto m = a + (b - a)/2;

        if (xs[m] == x)
            return m;
        else if (xs[m] > x)
            b = m - 1;
        else
            a = m + 1;
    }

    return -1;
}
