#include <bits/stdc++.h>

using namespace std;

string add(const string& a, const string& b)
{
    stack<int> x, y, z;
    
    for (const auto& c : a)
        x.push(c - '0');
    
    for (const auto& c : b)
        y.push(c - '0');
    
    auto N = max(a.size(), b.size()), carry = 0ul;
    
    while (N--) {
        auto c = x.empty() ? 0 : x.top();
        auto d = y.empty() ? 0 : y.top();
        auto res = c + d + carry;

        z.push(res % 10);
        carry = res / 10;

        if (not x.empty()) x.pop();
        if (not y.empty()) y.pop();
    }
    
    if (carry)
        z.push(carry);
    
    ostringstream oss;
    
    while (not z.empty())
    {
        oss << z.top();
        z.pop();
    }
    
    return oss.str();
}

int main()
{
    string a, b;
    
    cin >> a >> b;
    cout << a << " + " << b << " = " << add(a, b) << '\n';
    
    return 0;
}
