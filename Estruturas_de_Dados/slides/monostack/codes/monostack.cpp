#include <bits/stdc++.h>

using namespace std;

template<typename T>
class MonoStack {
public:
    void push(const T& x)
    {
        while (not st.empty() and st.top() > x)
            st.pop();

        st.emplace(x);
    }

    void pop() { st.pop(); };
    auto top() const { return st.top(); }
    bool empty() const { return st.empty(); }

private:
    stack<T> st;
};

template<typename T>
ostream& operator<<(ostream& os, const MonoStack<T>& ms)
{
    auto temp(ms);

    while (not temp.empty())
    {
        cout << temp.top() << ' ';
        temp.pop();
    }

    return os;
}

int main()
{
    vector<int> as { 1, 4, 3, 4, 2, 1, 3 };
    MonoStack<int> ms;

    for (auto& a : as)
    {
        ms.push(a);
        cout << ms << '\n';
    }

    return 0;
}
