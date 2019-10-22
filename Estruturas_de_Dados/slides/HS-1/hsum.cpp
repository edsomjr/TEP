int h(const string& K)
{
    int v = 0;
    
    for (const auto& c : K)
        v += c;

    return v;
}
