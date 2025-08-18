#include <bits/stdc++.h>

using namespace std;

template<typename T>
class MonoQueue {
public:
    void push(const T& x)
    {
        while (not st.empty() and st.back() > x)
            st.pop_back();

        st.emplace_back(x);
    }

    void pop() { st.pop_front(); };
    auto back() const { return st.back(); }
    auto front() const { return st.front(); }
    bool empty() const { return st.empty(); }

private:
    deque<T> st;
};

template<typename T>
ostream& operator<<(ostream& os, const MonoQueue<T>& ms)
{
    auto temp(ms);

    while (not temp.empty())
    {
        cout << temp.front() << ' ';
        temp.pop();
    }

    return os;
}

int main()
{
    vector<int> as { 1, 4, 3, 4, 2, 1, 3 };
    MonoQueue<int> mq;

    for (auto& a : as)
    {
        mq.push(a);
        cout << mq << '\n';
    }

    return 0;
}
