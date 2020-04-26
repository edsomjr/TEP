#include <iostream>
#include <algorithm>

using namespace std;

int median(int xs[], int N)
{
    nth_element(xs, xs + N/2, xs + N);

    return xs[N/2];
}

int main()
{
    int xs[] { 7, 1, 4, 8, 2, 6, 5, 9, 3 }, N = 9;

    cout << median(xs, N) << endl;

    return 0;
}
