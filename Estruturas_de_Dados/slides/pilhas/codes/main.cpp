#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<float, 10> s;

    cout << "Empty? " << s.empty() << '\n';

    s.push(1.8);
    s.push(-0.7);
    s.push(2.5);

    cout << "Top = " << s.top() << '\n';
    s.pop();

    cout << "Size = " << s.size() << '\n';
    cout << "Top = " << s.top() << '\n';

    cout << "Empty? " << s.empty() << '\n';

    s.clear();
    cout << "Empty? " << s.empty() << '\n';

    // Segmentation Fault: a pilha comporta, no máximo, 10 elementos
    for (int i = 0; i < 20; ++i)
        s.push(i*0.5);

    return 0;
}
