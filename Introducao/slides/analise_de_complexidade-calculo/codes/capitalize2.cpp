string capitalize(const string& s)
{
    auto r = s;
    r[0] = toupper(r[0]);

    return r;
}
