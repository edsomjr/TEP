#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int X, Y;
        cin >> X >> Y;

        cout << X + Y << endl;
    }

    return 0;
}
