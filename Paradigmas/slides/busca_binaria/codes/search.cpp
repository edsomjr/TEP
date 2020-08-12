int search(int x, const vector<int>& xs)
{
    for (size_t i = 0; i < xs.size(); ++i)
        if (xs[i] == x)
            return i;

    return -1;
}
