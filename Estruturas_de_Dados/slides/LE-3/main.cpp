#include <iostream>
#include "circular_list.h"

using namespace std;

int main()
{
    CircularList<int> clist { 1, 2, 3, 4, 5 };

    cout << clist << '\n';

    clist.push_back(6);
    clist.push_front(7);

    cout << clist << '\n';

    auto it = clist.begin();

    for (int i = 0; i < 20; ++i)
        cout << *it++ << ' ';
    cout << '\n';

    int counter = 0;

    while (not clist.empty())
    {
        counter++ % 2 ? clist.pop_front() : clist.pop_back();
        cout << clist << '\n';
    }

    cout << "Empty? " << clist.empty() << '\n';

    clist.push_back(10);
    clist.push_front(20);
    clist.push_back(30);

    cout << clist << '\n';

    return 0;
}
