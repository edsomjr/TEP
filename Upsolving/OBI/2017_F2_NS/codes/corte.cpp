int pieces(double x, int N, const vector<int>& hs)
{
    auto L = 0, res = 0;

    while (L < N)
    {
        auto R = L + 1;

        if (hs[L] > x)
        {
            while (R < N and hs[R] > x)
                ++R;

            ++res;
        }

        L = R;
    }

    return res + 1;
}
