#include <stack>
#include <iostream>

using namespace std;

int main () {
    stack<int> s;
    int t;

    s.push(1);
    s.push(10);
    
    while(!s.empty()) {
        t = s.front();
        foo(t);
        t.pop();
    }

    return 0;
}
