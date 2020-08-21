#include <iostream>

#define REP(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)

int main()
{
    int ns[] { 2, 3, 5, 8, 13, 21 };

    REP(i, 1, 4)
        std::cout << ns[i] << std::endl;      // 3 5 8 13

    return 0;
}
