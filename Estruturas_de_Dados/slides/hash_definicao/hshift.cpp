unsigned long h(const string& S) {
    unsigned long v = 0, p = 0, m = 4, i = 0;

    for (auto c : S) {
        p |= (c << 8*i++);

        if (i == m) v ^= p, i = p = 0; 
    }

    return v ^ p;
} 
