#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const vector<int> ps { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    int p = 21;

    auto it = find(ps.begin(), ps.end(), p);

    if (it != ps.end())
        cout << p << " encontrado na posicao " << it - ps.begin() << "\n";
    else
        cout << p << " nao encontrado\n";

    return 0;
}
