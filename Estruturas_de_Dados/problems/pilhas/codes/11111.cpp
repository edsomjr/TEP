#include <bits/stdc++.h>

using namespace std;

bool matrioska(const vector<int>& xs)
{
    stack<int> s;

    for (auto x : xs)
    {
        if (x < 0)
            s.push(x);
        else
        {
            int stacked = 0;

            while (not s.empty() and s.top() > 0)
            {
                stacked += s.top();
                s.pop();
            }

            if (stacked >= x or s.empty() or s.top() != -x)
                return false;

            s.pop();
            s.push(x);
        }
    }

    while (not s.empty() and s.top() > 0)
        s.pop();

    return s.empty();
}

int main()
{
    ios::sync_with_stdio(false);

    string line;

    while (getline(cin, line))
    {
        istringstream is(line);

        vector<int> xs;
        copy(istream_iterator<int>(is), istream_iterator<int>(), 
             back_inserter(xs));

        cout << ":-" << (matrioska(xs) ? ") Matrioshka!" : 
            "( Try again.") << '\n';
    }

    return 0;
}
