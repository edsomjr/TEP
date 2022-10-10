#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> xs { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
    auto x = xs.bucket_count();     // x = 11 buckets

    // Mostra a quantidade de elementos em cada bucket
    for (size_t i = 0; i < x; ++i)
        cout << xs.bucket_size(i) << ' ';
    cout << '\n';                   // 1 2 2 1 0 1 0 0 1 0 1

    x = xs.max_bucket_count();      // x = 1152921504606846975 

    auto y = xs.load_factor();      // y = 0.818182, size()/bucket_count()
    y = xs.max_load_factor();       // y = 1

    xs.insert(4);
    y = xs.load_factor();           // y = 0.909091
    xs.insert(6);
    y = xs.load_factor();           // y = 0.478261
    x = xs.bucket_count();          // x = 23 buckets

    // 0 1 1 1 1 1 1 0 1 1 0 1 0 1 0 0 0 0 0 0 0 1 0 
    for (size_t i = 0; i < x; ++i)
        cout << xs.bucket_size(i) << ' ';
    cout << '\n';                   

    xs.rehash(15);
    x = xs.bucket_count();          // x = 15
    y = xs.load_factor();           // y = 0.647059

    // 1 1 1 1 3 1 1 0 1 0 0 0 0 1 0 0 0 
    for (size_t i = 0; i < x; ++i)
        cout << xs.bucket_size(i) << ' ';
    cout << '\n';                   

    return 0;
}
