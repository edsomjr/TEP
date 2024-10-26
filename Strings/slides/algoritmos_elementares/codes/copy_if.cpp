#include <cctype>
#include <algorithm>

// Extrai apenas as vogais de s
std::string filter_vowels(const std::string& s)
{
    string v;

    std::copy_if(s.begin(), s.end(), back_inserter(v),
        [](char c)
        {
            const std::string vowels { "aeiou" };

            return vowels.find(c) != string::npos;
        }
    );
            
    return v;
}
