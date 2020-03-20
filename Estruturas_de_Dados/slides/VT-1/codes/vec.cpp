#include <iostream>
#include <vector>

int main() {
    std::vector<int> ns { 1, 1, 2, 3, 5, 8, 13, 21 };

    std::cout << "ns tem " << ns.size() << " elementos\n";
    ns.clear();
    std::cout << "ns tem " << ns.size() << " elementos\n";

    for (int i = 1; i <= 10; ++i)
        ns.push_back(i);

    ns.pop_back();

    std::cout << "ns: ";
    for (size_t i = 0; i < ns.size(); ++i)
        std::cout << ns[i] << (i + 1 == ns.size() ? "\n" : " ");

    return 0;
}
