#include <bits/stdc++.h>

using namespace std;

template<typename T1, typename T2>
vector<pair<T1, T2>> cartesian_product(const vector<T1>& A, const vector<T2>& B)
{
    vector<pair<T1, T2>> AB;

    for (const auto& a : A)
        for (const auto& b : B)
            AB.emplace_back(a, b);

    return AB;
}

int main()
{
    vector<char> A { 'a', 'b', 'c' };
    vector<int> B { 1, 2 };

    for (const auto& [a, b] : cartesian_product(A, B))
        cout << "(" << a << ", " << b << ")\n";

    return 0;
}
