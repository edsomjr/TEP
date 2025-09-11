#include <bits/stdc++.h>

using namespace std;

template<typename T, size_t N>
class Queue {
public:
    Queue() : first(0), last(0), _size(0) {}

    void clear() { first = last = _size = 0; }
    bool empty() const { return _size == 0; }
    size_t size() const { return _size; }

    void push(const T& x) {
        if (_size == N) throw "Fila cheia"; 

        elems[last] = x;
        last = (last + 1) % N;
        _size++;
    }

    void pop()
    {
        if (_size == 0) throw "Fila vazia";

        first = (first + 1) % N;
        _size--;
    }

    const T& front() const
    {
        if (_size == 0) throw "Fila vazia";

        return elems[first];
    }

private:
    array<T, N> elems;
    int first, last;
    size_t _size;
};

int main() {
    Queue<int, 10> q;

    cout << "Empty? " << q.empty() << '\n';

    for (int i = 1; i <= 10; ++i) q.push(i);

    cout << "Size = " << q.size() << '\n';
    cout << "Front = " << q.front() << '\n';

    for (int i = 0; i < 5; ++i) q.pop();

    q.push(11);
    q.push(12);

    cout << "Size = " << q.size() << '\n';
    cout << "Front = " << q.front() << '\n';

    return 0;
}
