    int F(int n)
    {
        return n <= 1 ? n : F(n - 1) + F(n - 2);
    }
