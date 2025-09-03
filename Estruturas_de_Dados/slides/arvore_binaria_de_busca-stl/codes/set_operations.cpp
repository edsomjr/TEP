#include <set>

int main()
{
    std::set<int> s;

    s.insert(3);            // s = { 3 }
    s.emplace(3);           // s = { 3 }
    s.insert( { 1, 2 } );   // s = { 1, 2, 3 }

    auto n = s.erase(3);    // n = 1
    n = s.erase(4);         // n = 0

    n = s.count(1);         // n = 1
    
    auto it = s.find(3);    /// n = s.end()

    return 0;
}
