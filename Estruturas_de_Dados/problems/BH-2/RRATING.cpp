#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

    size_t total = 0;

    while (N--)
    {
        int cmd, x;
        cin >> cmd;

        switch (cmd) {
        case 1:
            cin >> x;

            lo.push(x);
            ++total;

            if (hi.size() < total / 3)
            {
                hi.push(lo.top());
                lo.pop();
            }

            while (not hi.empty() and lo.top() > hi.top())
            {
                auto x = lo.top();
                auto y = hi.top();

                lo.pop();
                hi.pop();

                hi.push(x); 
                lo.push(y); 
            }

            break;

        default:
            if (hi.empty())
                cout << "No reviews yet\n";
            else
                cout << hi.top() << '\n';
        }
    }

    return 0;
}
