int binary_search(int x, const vector<int>& v) {
    int N = v.size(), a = 0, b = N - 1;

    while (a <= b) {
        auto m = a + (b - a)/2;

        if (x < v[m])
            b = m - 1;
        else if (x > v[m])
            a = m + 1;
        else
            return m;
    }

    return -1;
}
