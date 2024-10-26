#include <cctype>

bool is_vowel(char c)
{
    const std::string vowels { "aeiou" };

    return vowels.find(tolower(c)) != std::string::npos;
}

std::string filter_vowels(const std::string& s)
{
    std::string v;

    for (auto c : s)
        if (is_vowel(c))
            v.push_back(c);

    return v;
}
