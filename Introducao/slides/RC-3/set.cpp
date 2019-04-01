#include <set>
#include <iostream>

using namespace std;

int main () {
    set<int> s { 1, 2, 3, 10, 15 };
    
    s.insert(1); // s = { 1, 2, 3, 10, 15 }
    
    auto it = s.find(2); // it é o iterador para o elemento 2

    for(auto i = it; i != s.end(); i++)
        cout << *i << " ";
    cout << endl;
    // 3 10 15

    return 0;
}
