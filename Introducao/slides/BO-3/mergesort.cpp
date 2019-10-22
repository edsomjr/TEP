#include <bits/stdc++.h>

using namespace std;

template<typename RandIt>
void merge(size_t N, RandIt first, RandIt middle, RandIt last)
{
    vector<typename iterator_traits<RandIt>::value_type> temp(N);
    auto it = first, jt = middle;
    auto k = 0;

    while (it != middle and jt != last) {
        temp[k++] = min(*it, *jt);
        temp[k - 1] == *it ? ++it : ++jt;
    }

    while (it != middle)
        temp[k++] = *it++;

    while (jt != last)
        temp[k++] = *jt++;

    for (const auto& elem : temp)
        *first++ = elem;
}

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
    auto N = last - first;

    if (N == 1)
        return;

    auto middle = first + (N + 1)/2;

    mergesort(first, middle);
    mergesort(middle, last);

    merge(N, first, middle, last);
}

int main()
{
    vector<int> xs { 89, 60, 12, 45, 37, 52, 33, 97, 20 };

    mergesort(xs.begin(), xs.end());

    for (size_t i = 0; i < xs.size(); ++i)
        cout << xs[i] << (i + 1 == xs.size() ? '\n' : ' ');

    return 0;
}
