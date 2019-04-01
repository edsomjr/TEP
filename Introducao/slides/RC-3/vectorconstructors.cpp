#include <vector>

using namespace std;

int main () {
    vector<int> v0;          // empty vector
    vector<int> v1(5);       // v1 = 0 0 0 0 0
    vector<int> v2(5, 1);    // v2 = 1 1 1 1 1
    vector<int> v3(v2);      // v3 = v2
    vector<int> v4 {1, 3};   // v4 = 1 3

    return 0;
}
