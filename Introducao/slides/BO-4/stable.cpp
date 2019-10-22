// Baseado no exemplo ilustrado no cppman
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> xs { 2.7, 2.2, 1.8, 1.3, 1.1, 3.2, 2.9 }, ys = xs;
    auto cmp = [](double a, double b) { return int(a) < int(b); };

    sort(xs.begin(), xs.end());             // 1.1 1.3 1.8 2.2 2.7 2.9 3.2
    stable_sort(ys.begin(), ys.end(), cmp); // 1.8 1.3 1.1 2.7 2.2 2.9 3.2

    return 0;
}
