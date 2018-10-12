#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> ns { 8, 5, 1, 3, 2, 9, 6, 4, 10, 7 };

    sort(ns.begin(), ns.end());

    for (size_t i = 0; i < ns.size(); ++i)
        cout << ns[i] << (i + 1 == ns.size() ? "\n" : ", ");

    sort(ns.begin(), ns.end(), greater<int>());

    for (size_t i = 0; i < ns.size(); ++i)
        cout << ns[i] << (i + 1 == ns.size() ? "\n" : ", ");

    return 0;
}
