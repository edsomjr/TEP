#include <set>

int main()
{
    std::set<int> s;

    auto ok = s.empty();            // ok = true
    auto N = s.size();              // N = 0

    s.insert( {10, 20, 30, 40, 50} );

    auto it = s.lower_bound(17);    // *it = 20
    it = s.lower_bound(30);         // *it = 30

    it = s.upper_bound(30);         // *it = 40 
    it = s.upper_bound(50);         // *it = s.end()

    return 0;
}
