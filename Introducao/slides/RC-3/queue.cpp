#include <queue>
#include <iostream>

using namespace std;

int main () {
    queue<int> q;
    int f;

    q.push(1);
    q.push(10);
    
    while(!q.empty()) {
        f = q.front();
        foo(f);
        q.pop();
    }

    return 0;
}
