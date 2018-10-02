#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void insert_sort(vector<T>& as)
{
    int N = as.size();

    for (int i = 1, j; i < N; ++i)
    {
        auto v = as[i];

        for (j = i; j and as[j - 1] > v; --j)
            as[j] = as[j - 1];

        as[j] = v;
    }
}

int main()
{
    vector<int> as { 3, 5, 1, 2, 4 };

    insert_sort<int>(as);

    for (size_t i = 0; i < as.size(); ++i)
        cout << as[i] << (i + 1 == as.size() ? '\n' : ' ');

    return 0;
}
