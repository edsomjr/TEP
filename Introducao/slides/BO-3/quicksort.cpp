#include <bits/stdc++.h>

using namespace std;

template<typename RandIt>
RandIt partitioning(RandIt first, RandIt last)
{
    auto N = last - first;
    RandIt p = first + (rand() % N);    // slide: RandIt p = first + 3;

    swap(*first, *p);
    p = first;
    RandIt i = first + 1;

    for (RandIt j = first + 1; j < last; ++j)
        if (*j < *p)
        {
            swap(*j, *i);
            ++i;
        }

    swap(*p, *(--i));

    return i;
}

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last)
{
    auto p = partitioning(first, last);

    cout << *p << '\n';
}

int main()
{
    srand(time(NULL));

    vector<int> xs { 89, 60, 12, 45, 37, 52, 33, 97, 20 };

    quicksort(xs.begin(), xs.end());

    for (size_t i = 0; i < xs.size(); ++i)
        cout << xs[i] << (i + 1 == xs.size() ? '\n' : ' ');

    return 0;
}
