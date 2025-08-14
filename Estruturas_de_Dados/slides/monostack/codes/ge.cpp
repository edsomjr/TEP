#include <bits/stdc++.h>

using namespace std;

auto ge(const vector<int>& as)
{
    auto N = (int) as.size();
    vector<int> pge(N, -1), nge(N, N);

    stack<int> st;

    for (int i = 0; i < N; ++i)
    {
        while (not st.empty() and as[st.top()] <= as[i])
        {
            nge[st.top()] = i;
            st.pop();
        }

        if (not st.empty())
            pge[i] = st.top();

        st.emplace(i);
    }

    return make_pair(pge, nge);
}

int main()
{
    vector<int> as { 1, 4, 3, 5, 2, 0, 6 };
    auto [pge, nge] = ge(as);

    cout << "i:   ";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << setfill(' ') << i << (i + 1 == as.size() ? '\n' : ' ');

    cout << "as:  ";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << setfill(' ') << as[i] << (i + 1 == as.size() ? '\n' : ' ');

    cout << "pge: ";
    for (size_t i = 0; i < pge.size(); ++i)
        cout << setw(2) << setfill(' ') << pge[i] << (i + 1 == pge.size() ? '\n' : ' ');

    cout << "nge: ";
    for (size_t i = 0; i < nge.size(); ++i)
        cout << setw(2) << setfill(' ') << nge[i] << (i + 1 == nge.size() ? '\n' : ' ');

    return 0;
}
