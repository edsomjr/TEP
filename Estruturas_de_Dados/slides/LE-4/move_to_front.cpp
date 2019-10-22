#include <bits/stdc++.h>

using namespace std;

template<typename T>
class MoveToFront {
    friend ostream& operator<<(ostream& os, const MoveToFront& mtf)
    {
        for (const auto& x : mtf.elements)
            os << x;

        os << " (" << mtf.comparisons << "/" << mtf.total << ")";

        return os;
    }

public:
    bool search(const T& info)
    {
        auto it = find(elements.begin(), elements.end(), info);
        bool found = true;

        total += elements.size();

        auto dist = distance(elements.begin(), it);
        comparisons += (it == elements.end() ? dist : dist + 1);

        if (it == elements.end()) {
            elements.push_back(info);
            found = false;
        } else {
            elements.erase(it);
            elements.push_front(info);
        }
 
        return found;
    }

private:
    list<T> elements;
    int comparisons = 0, total = 0;
};

int main()
{
    const string message { "ACBCDADACACCEE" };
    MoveToFront<char> mtf;

    for (const auto& c : message) {
        mtf.search(c);
        cout << mtf << '\n';
    }
}
