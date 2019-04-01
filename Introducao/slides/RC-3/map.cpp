#include <map>
#include <iostream>

using namespace std;

int main () {
    map<char, int> m;
    string s = "Hello";

    for(auto c : s)
        m[c]++;

    for(auto const& [key, value] : m) {
        cout << "Letra "
             << key
             << ": "
             << value << endl;
    }

    // output:
    // Letra H: 1
    // Letra e: 1
    // letra l: 2
    // letra o: 1

    return 0;
}
