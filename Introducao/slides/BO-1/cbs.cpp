#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int compare(const void *a, const void *b)
{
    const int *x = (const int *) a, *y = (const int *) b;
    return *x == *y ? 0 : (*x < *y ? -1 : 1);
}

int main()
{
    int ns[] { 2, 18, 45, 67, 99, 99, 99, 112, 205 }, N = 9, n = 99;
    auto p = (int *) bsearch(&n, ns, N, sizeof(int), compare);

    if (p == NULL)
        cout << "Elemento " << n << " não encontrado\n";
    else
        cout << n << " encontrado na posição: " << p - ns << "\n";

    n = 100;

    cout << "Elemento " << n << (binary_search(ns, ns + N, n) ? 
        " " : " não ") << "encontrado\n";

    n = 99;

    auto it = lower_bound(ns, ns + N, n);
    cout << "Cota inferior de " << n << ": " << it - ns << endl;

    auto jt = upper_bound(ns, ns + N, n);
    cout << "Cota superior de " << n << ": " << jt - ns << endl;

    cout << "Número de aparições de " << n << ": " << jt - it << endl;

    return 0;
}
