#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void bubble_sort(vector<T>& as) {
    int N = as.size();
    bool updated;

    do {
        updated = false;

        for (int i = 1; i < N; ++i) {
            if (as[i - 1] > as[i]) {
                updated = true;
                swap(as[i - 1], as[i]);
            }
        }
    } while (updated);
}

int main()
{
    vector<int> as { 3, 5, 1, 2, 4 };

    bubble_sort<int>(as);

    for (size_t i = 0; i < as.size(); ++i)
        cout << as[i] << (i + 1 == as.size() ? '\n' : ' ');

    return 0;
}
