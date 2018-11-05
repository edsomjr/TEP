#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Alphabetical {
    friend ostream& operator<<(ostream& os, const Alphabetical& none) {
        for (const auto& x : none.elements)
            os << x;
        return os;
    }

public:
    bool search(const T& info) {
        auto it = find(elements.begin(), elements.end(), info);

        if (it != elements.end())
            return true;

        insert(info);

        return false;
    }

private:
    list<T> elements;

    void insert(const T& info) {
        elements.push_back(info);

        auto it = elements.rbegin();

        while (it != elements.rend())
        {
            auto nxt = next(it);

            if (*it < *nxt)
                swap(*it, *nxt);

            it = nxt;
        }
    }
};

int main()
{
    const string message { "ACBCDADACACCEE" };
    Alphabetical<char> auto_list;

    for (const auto& c : message) {
        auto_list.search(c);
        cout << auto_list << '\n';
    }
}
