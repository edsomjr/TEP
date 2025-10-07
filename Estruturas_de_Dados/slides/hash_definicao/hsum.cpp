int h(const string& K)
{
    int v = 0;
    
    for (auto c : K)
        v += c;

    return v;
}
