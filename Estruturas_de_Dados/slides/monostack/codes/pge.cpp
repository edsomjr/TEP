#include <bits/stdc++.h>

using namespace std;

template<typename T>
class MonoStack {
public:
    MonoStack(int start_idx = 0, inc = 1) : pos(start_idx), invalid(start_idx - inc) {}

    int push(const T& x) {
        while (not st.empty() and st.top().second <= x)
            st.pop();

        auto i = st.empty() ? invalid : st.top().first;
        st.emplace(pos, x);
        pos += inc;

        return i;
    }

    void pop() { st.top(); };
    auto top() const { return st.top(); }
    bool empty() const { return st.empty(); }

private:
    stack<pair<int, T>> st;
    int pos, invalid;
};

auto pge(const vector<int>& xs)
{
    MonoStack<int> ms;
    vector<int> ans;

    for (auto x : xs)
        ans.emplace_back(ms.push(x));

    return ans;
}

int main()
{
    vector<int> as { 1, 4, 3, 4, 2, 1, 3 };
    auto is = pge(as);

    cout << "i:   ";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << setfill(' ') << i << (i + 1 == as.size() ? '\n' : ' ');

    cout << "as:  ";
    for (size_t i = 0; i < as.size(); ++i)
        cout << setw(2) << setfill(' ') << as[i] << (i + 1 == as.size() ? '\n' : ' ');

    cout << "pge: ";
    for (size_t i = 0; i < is.size(); ++i)
        cout << setw(2) << setfill(' ') << is[i] << (i + 1 == is.size() ? '\n' : ' ');

    return 0;
}
