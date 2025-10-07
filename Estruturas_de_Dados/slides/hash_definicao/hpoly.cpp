unsigned long h(const string& K, size_t p, size_t T)
{
    unsigned long h = 0;

    for (int i = K.size() - 1; i >= 0; --i) {
        h = (h * p) % T;
        h = (h + K[i]) % T;
    }
    
    return h;
}
