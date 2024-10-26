#include <algorithm>

bool is_anagram(const std::string& s, const std::string& t)
{
    std::string a(s), b(t);

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return a == b;
}
