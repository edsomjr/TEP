#include <bits/stdc++.h>

int main() {
    std::vector<int> ns { 1, 1, 2, 3, 5, 8, 13, 21 };

    std::cout << "ns tem " << ns.size() << " elementos\n";

    ns.clear();
    std::cout << "ns tem " << ns.size() << " elementos\n";

    for (int i = 1; i <= 10; ++i)
        ns.emplace_back(i);

    ns.pop_back();

    std::cout << "ns: ";

    for (size_t i = 0; i < ns.size(); ++i)
        std::cout << ns[i] << (i + 1 == ns.size() ? "\n" : " ");

    std::vector<int> xs(9, 123);

    std::cout << "xs tem " << xs.size() << " elementos, todos iguais a " << xs.front() << '\n';

    std::iota(xs.begin(), xs.end(), 1);

    std::cout << "xs:";

    for (auto x : xs)
        std::cout << ' ' << x;
    std::cout << '\n';

    std::cout << (ns == xs ? "Sim" : "Nao") << '\n';

    return 0;
}
