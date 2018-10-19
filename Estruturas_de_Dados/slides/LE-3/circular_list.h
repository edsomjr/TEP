#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <ostream>
#include <initializer_list>

template<typename T>
class CircularList {

    friend
    std::ostream& operator<<(std::ostream& os, const CircularList& list) {
        os << "[";

        if (not list.empty()) {
            auto it = list.begin();

            do {
                os << " " << *it;
                it++;
            } while (it != list.begin());
        }

        os << " ]";

        return os;
    }

private:
    struct Node {
        T info;
        Node *prev, *next;

        Node(const T& i, Node *p, Node *n) : info(i), prev(p), next(n) {}
    };

    Node *head, *tail;
    unsigned long _size;

public:
    CircularList() : head(nullptr), tail(nullptr), _size(0) {}

    CircularList(std::initializer_list<T> source)
        : head(nullptr), tail(nullptr), _size(0)
    {
        for (auto it = source.begin(); it != source.end(); ++it)
            push_back(*it);
    }

    ~CircularList() 
    {
        if (head == nullptr)
            return;

        auto p = head;

        do {
            auto next = p->next;
            delete p;
            p = next;
        } while (p != head);
    }

    const T& front() const
    {
        if (head)
            return head->info;
        else
            throw "Empty list!";
    }

    const T& back() const
    {
        if (tail)
            return tail->info;
        else
            throw "Empty list!";
    }

    bool empty() const { return head == nullptr; }

    unsigned long size() const { return _size; }

    class iterator {
    public:
        explicit iterator(Node *n) : node(n) {}

        // Prefix
        iterator& operator++() {
            node = node->next;
            return *this;
        }

        // Posfix
        iterator& operator++(int) {
            return ++(*this);
        }

        iterator& operator--() {
            node = node->prev;
            return *this;
        }

        bool operator==(const iterator& it) const
        {
            return node == it.node;
        }

        bool operator!=(const iterator& it) const
        {
            return not (*this == it);
        }

        T& operator*() const {

            if (node == nullptr)
                throw "Invalid iterator";

            return node->info;
        }

    private:
        Node *node;
    };

    iterator begin() const {
        return iterator(head);
    }

    void push_front(const T& info)
    {
        auto n = new Node(info, nullptr, head);

        head ? head->prev = n : tail = n;
        head = n;

        head->prev = tail;
        tail->next = head;

        _size++;
    }

    void push_back(const T& info)
    {
        auto n = new Node(info, tail, nullptr);

        tail ? tail->next = n : head = n; 
        tail = n;

        tail->next = head;
        head->prev = tail;

        _size++;
    }

    void pop_front()
    {
        if (!head)
            throw "Lista vazia";

        auto temp = head;
        head = _size > 1 ? head->next : nullptr;
        delete temp;

        head ? head->prev = tail, tail->next = head : tail = nullptr;
        _size--;
    }

    void pop_back()
    {
        if (!tail)
            throw "Lista vazia";

        auto temp = tail;
        tail = _size > 1 ? tail->prev : nullptr;
        delete temp;        

        tail ? tail->next = head, head->prev = tail : head = nullptr;
        _size--;
    }
};

#endif
