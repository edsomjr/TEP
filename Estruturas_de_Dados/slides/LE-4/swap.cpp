#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Swap {
    friend ostream& operator<<(ostream& os, const Swap& none) {
        for (const auto& x : none.elements)
            os << x;
        return os;
    }

public:
    bool search(const T& info) {
        auto it = find(elements.begin(), elements.end(), info);

        if (it == elements.end()) {
            insert(info);
            return false;
        } else if (it != elements.begin()) {
            swap(*it, *prev(it));
        }
 
        return true;
    }

private:
    list<T> elements;

    void insert(const T& info) {
        elements.push_back(info);
    }
};

int main()
{
    const string message { "ACBCDADACACCEE" };
    Swap<char> auto_list;

    for (const auto& c : message) {
        auto_list.search(c);
        cout << auto_list << '\n';
    }
}
