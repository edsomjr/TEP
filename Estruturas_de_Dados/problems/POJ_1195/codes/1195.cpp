#include <iostream>
#include <vector>

using namespace std;

const int MAX { 1030 };
int ft[MAX][MAX];

class BITree2D {
public:
    int N;

    BITree2D() : N(0) {}

    void set_n(size_t n) { N = n; }

    int RSQ(int a, int b, int c, int d)         // Range query
    {
        return RSQ(c, d) - RSQ(c, b-1) - RSQ(a-1, d) + RSQ(a-1, b-1);
    }

    void add(int x, int y, int v)               // Point update
    {
        for (int i = x; i <= N; i += LSB(i))
            for (int j = y; j <= N; j += LSB(j))
                ft[i][j] += v;
    }

private:
    int LSB(int n) { return n & -n; }

    int RSQ(int a, int b) {
        int sum = 0;
        
        for (int i = a; i > 0; i -= LSB(i))
            for (int j = b; j > 0; j -= LSB(j))
                sum += ft[i][j];

        return sum;
    }
};

int main()
{
    int cmd, a, b, c, d;
    BITree2D ft;

    while (cin >> cmd, cmd != 3)
    {
        switch (cmd) {
        case 0:
            cin >> a;
            ft.set_n(a);
            break;

        case 1:
            cin >> a >> b >> c;
            ft.add(a + 1, b + 1, c);
            break;

        default:
            cin >> a >> b >> c >> d;
            cout << ft.RSQ(a + 1, b + 1, c + 1, d + 1) << '\n';
        }
    }

    return 0;
}
