#include <iostream>
#include <stack>
#include <map>

using namespace std;

bool is_valid(const string& expression)
{
    static map<char, char> open { {')', '('}, {']', '['}, {'}', '{'}, };
    stack<char> s;
        
    for (auto c : expression)
    {
        switch (c) {
        case '(':
        case '[':
        case '{':
            s.push(c);
            break;

        case ')':
        case ']':
        case '}':
            if (s.empty() || s.top() != open[c])
                return false;

            s.pop();
        }
    }
    
    return s.empty();
}

int main()
{
    string expression;
    getline(cin, expression);
    cout << (is_valid(expression) ? "Ok" : "Invalid") << '\n';
    return 0;
}
