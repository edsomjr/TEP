#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    vector<int> v {0, 1, 2};

    v.push_back(3);
    // v : 0 1 2 3

    cout << v[0] << endl;
    // prints: 0

    cout << v.back() << endl;
    // prints: 3
    
    v.pop_back();
    cout << v.back() << endl;
    // prints: 2
    
    // v : 0 1 2
    auto it = v.begin() + 1;
    v.erase(it);
    // v : 0 2
    
    auto found = find(v.begin(), v.end(), 2);
    if(found != v.end())
        cout << *found << endl;
        // prints: 2

    for(auto e : v)
        cout << e << " ";
    cout << endl;
    // prints: 0 2

    return 0;
}
