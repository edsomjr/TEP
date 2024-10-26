#include <map>

std::map<char, int> histogram(const std::string& s)
{
    std::map<char, int> h;

    for (auto c : s)
        ++h[c];

    return h;
}
