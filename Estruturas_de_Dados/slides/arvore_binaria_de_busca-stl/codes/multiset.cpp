#include <bits/stdc++.h>

int main() {
    std::multiset<int> ms { 1, 2, 2, 2, 3 };
    auto n = ms.count(2);                           // n = 3
    auto it = ms.find(2);

    ms.erase(it);                                   // ms = { 1, 2, 2, 3 }
    n = ms.count(2);                                // n = 2
    ms.erase(2);
    ms.count(2);                                    // n = 0

    ms.insert( { 2, 2, 2, 2 } );
    auto [a, b] = ms.equal_range(2);

    for (auto i = a; i != b; ++i)
        std::cout << *i << '\n';                   // 2 2 2 2

    return 0;
}
