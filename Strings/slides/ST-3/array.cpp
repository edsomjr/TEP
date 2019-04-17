#include <cstring>

void histogram(int h[256], const string& s)
{
    memset(h, 0, sizeof h);

    for (auto c : s)
        ++h[c];
}
