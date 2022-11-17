#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> A { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };        // Conjunto A
    vector<int> B { 2, 3, 5, 7, 11, 13 };                   // Conjunto B
    vector<int> C;
    
    set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    // C = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13 }
    cout << "union = ";
    for (size_t i = 0; i < C.size(); ++i)
        cout << C[i] << (i + 1 == C.size() ? '\n' : ' ');   

    C.clear();
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    cout << "intersection = ";
    for (size_t i = 0; i < C.size(); ++i)
        cout << C[i] << (i + 1 == C.size() ? '\n' : ' ');   // C = { 2, 3, 5, 7 }

    C.clear();
    set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

    cout << "difference = ";
    for (size_t i = 0; i < C.size(); ++i)
        cout << C[i] << (i + 1 == C.size() ? '\n' : ' ');   // C = { 1, 4, 6, 8, 9, 10 }

    return 0;
}
