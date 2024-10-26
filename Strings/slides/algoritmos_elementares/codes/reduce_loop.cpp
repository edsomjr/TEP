// Soma todos os dígitos da strings de dígitos s
int sum(const std::string& s)
{
    int s = 0;

    for (auto c : s)
        s += (c - '0');

    return s;
}
