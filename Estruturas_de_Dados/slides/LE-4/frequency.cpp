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
            histogram[info] = 1;
            return false;
        } else {
            ++histogram[info];

            while (it != elements.begin())
            {
                auto p = prev(it);

                if (histogram[*p] < histogram[*it])
                    swap(*it, *p);

                it = p;
            }
        }
 
        return true;
    }

private:
    list<T> elements;
    map<T, int> histogram;

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
