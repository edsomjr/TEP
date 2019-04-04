#include <set>
#include <iostream>

int main() {
    std::multiset<int> ms { 1, 2, 2, 2, 3 };
    auto n = ms.count(2);               // n = 3
    auto it = ms.find(2);

    ms.erase(it);                       // ms = { 1, 2, 2, 3 }
    n = ms.count(2);                    // n = 2
    ms.erase(2);
    ms.count(2);                        // n = 0

    ms.insert( { 2, 2, 2, 2 } );
    auto p = ms.equal_range(2);

    for (auto it = p.first; it != p.second; ++it)
        std::cout << *it << '\n';       // 2 2 2 2

    return 0;
}
