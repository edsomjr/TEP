#ifndef STACK_H
#define STACK_H

#include <array>

template<typename T, size_t N>
class Stack {
public:
    Stack() : pos(0) {}

    void clear() { pos = 0; }
    bool empty() const { return pos == 0; }
    size_t size() const { return pos; }

    void push(const T& x) { elems[pos++] = x; }
    void pop() { pos--; }
    const T& top() const { return elems[pos - 1]; }

private:
    std::array<T, N> elems;
    size_t pos;
};

#endif
