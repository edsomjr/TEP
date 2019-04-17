#include <cctype>
#include <algorithm>

// Extrai apenas as vogais de s
string filter_vowels(const string& s)
{
    string v;

    copy_if(s.begin(), s.end(), back_inserter(v),
        [](char c)
        {
            const string vowels { "aeiou" };

            return vowels.find(c) != string::npos;
        }
    );
            
    return v;
}
