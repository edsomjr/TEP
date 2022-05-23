#include <algorithm>

bool is_anagram(const string& s, const string& t)
{
    string a(s), b(t);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}
