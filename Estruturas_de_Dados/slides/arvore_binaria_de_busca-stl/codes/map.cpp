#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    map<int, int> m1;          // Mapa de pares de inteiros vazio

    map<int, char> m2 { { 1, 'a' }, { 2, 'b' }, { 3, 'c' } };

    map<int, char> m3(m2);                      // m3 == m2

    map<int, char> m4(m2.begin(), m2.end());    // m4 == m2

    map<int, char> m5(move(m2));                // m5 == m4, m2 vazio

    map<string, int> m;

    m["abc"] = 1;                       // m = { "abc": 1 }
    m.insert(make_pair("xyz", 2));      // m = { "abc": 1, "xyz": 2 }

    m.erase("xyz");                     // m = { "abc": 1 }

    auto it = m.find("xyz");            // it == m.end()

    auto n = m.count("abc");            // n == 1

    m.insert({ { "xyz", 2 }, { "rst", 3 } });

    for (auto [x, y] : m)
        cout << x << ": " << y << endl;

    auto ok = m.empty();                // ok == false
    n = m.size();                       // n = 3

    it = m.lower_bound("mno");          // *it == { "rst", 3 };
    it = m.lower_bound("abc");          // *it == { "abc", 1 };
    it = m.upper_bound("zzz");          // *it == m.end();

    multimap<int,int> ms {{1, 1}, {1, 2}, {1, 2}, {1, 3}, {2, 1}, {2, 2}};

    n = ms.count(1);                    // n = 4
    n = ms.count(2);                    // n = 2

    // 1: 1, 1: 2, 1: 2, 1: 3, 2: 1, 2: 2
    for (auto it : ms)
        cout << it.first << ": " << it.second << ", ";
    cout << endl;

    //ms[1] = 4;                          // Erro de compilação!

    ms.erase(1);

    // 2: 1
    // 2: 2
    for (auto it : ms)
        cout << "--- " << it.first << ": " << it.second << endl;

    return 0;
}
