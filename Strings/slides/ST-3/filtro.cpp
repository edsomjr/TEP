#include <cctype>

bool is_vowel(char c)
{
    const string vowels { "aeiou" };

    return vowels.find(tolower(c)) != string::npos;
}

// Extrai apenas as vogais de s
string filter_vowels(const string& s)
{
    string v;

    for (auto c : s)
        if (is_vowel(c))
            v.push_back(c);

    return v;
}
