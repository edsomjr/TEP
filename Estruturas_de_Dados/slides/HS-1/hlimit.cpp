unsigned long h(const string& S) {
    string s(S);

    while (s.size() % 3) s.push_back(0);

    unsigned long v = 0, N = s.size(), M = N/3;

    for (size_t i = 0; i < M; ++i)
        v ^= (s[i] ^ s[2*M - 1 - i] ^ s[2*M + i]);

    return v;
} 
