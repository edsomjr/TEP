#include <iostream>

using namespace std;

int main()
{
    int A = 2046;                   // A = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
    int B = 10412;                  // B = { 2, 3, 5, 7, 11, 13 }
    int C = A | B;                  // C = 12286

    cout << "union = ";
    for (int x = 0; x < 32; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                   // C = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13 }

    C = A & B;                      // C = 172

    cout << "intersection = ";
    for (int x = 0; x < 32; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                   // C = { 2, 3, 5, 7 }

    C = A & ~B;                     // C = 1874

    cout << "difference = ";
    for (int x = 0; x < 32; ++x)
        if (C & (1 << x))
            cout << x << " ";
    cout << endl;                   // C = { 1, 4, 6, 8, 9, 10 }

    return 0;
}
