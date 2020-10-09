    auto it = unique(hs.begin(), hs.end());

    N = (int) distance(hs.begin(), it);
    hs.resize(N);
