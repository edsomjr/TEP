// Observe que a função abaixo identifica s corretamente
// mesmo nos casos onde |s| é ímpar
bool is_palindrome(const string& s)
{
    size_t N = s.size();

    for (size_t i = 0; i < N/2; ++i)
        if (s[i] != s[N - 1 - i])
            return false;

    return true;
}
