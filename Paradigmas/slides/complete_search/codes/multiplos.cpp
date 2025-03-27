#include <bits/stdc++.h>

using namespace std;

vector<int> filter(int N, int a, int b)
{
    vector<int> ms;

    for (int i = 1; i <= N; ++i)
        if (i % a == 0 or i % b == 0)
            ms.emplace_back(i);

    return ms;
}

vector<int> generator(int N, int a, int b)
{
    vector<int> ms;

    for (int i = a; i <= N; i += a)
        ms.emplace_back(i);

    for (int i = b; i <= N; i += b)
        if (i % a)              // Evita duplicatas
            ms.emplace_back(i);

    return ms;
}

int main()
{
    int N, a, b;
    cin >> N >> a >> b;

    auto ms = filter(N, a, b);

    cout << "Solução usando filtro: ";

    for (size_t i = 0; i < ms.size(); ++i)
        cout << ms[i] << (i + 1 == ms.size() ? "\n" : " ");

    ms = generator(N, a, b);

    cout << "Solução usando gerador: ";

    for (size_t i = 0; i < ms.size(); ++i)
        cout << ms[i] << (i + 1 == ms.size() ? "\n" : " ");

    return 0;
}
