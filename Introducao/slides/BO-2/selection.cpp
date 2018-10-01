#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void selection_sort(vector<T>& as)
{
    int N = as.size();

    for (int i = 0; i < N; ++i)
    {
        int k = i;                      // k = índice do menor elemento

        for (int j = i + 1; j < N; ++j)
            if (as[j] < as[k])
                k = j;

        swap(as[i], as[k]);
    }
}

int main()
{
    vector<int> as { 3, 5, 1, 2, 4 };

    selection_sort<int>(as);

    for (size_t i = 0; i < as.size(); ++i)
        cout << as[i] << (i + 1 == as.size() ? '\n' : ' ');

    return 0;
}
