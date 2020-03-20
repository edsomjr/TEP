#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    stack<int, vector<int>> s, t;

    cout << "Empty? " << s.empty() << '\n';

    for (int i = 1; i <= 10; ++i)
        s.push(2*i);

    s.pop();

    cout << "Top = " << s.top() << '\n'; 
    cout << "Size = " << s.size() << '\n'; 

    s.swap(t);

    cout << "Size = " << s.size() << '\n'; 
    cout << "T size = " << t.size() << '\n'; 
    cout << "T empty? " << t.empty() << '\n'; 

    return 0;
}
