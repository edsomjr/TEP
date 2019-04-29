#include <bits/stdc++.h>

template<typename T, int M>
class BTree {
private:
    struct Node {
        bool leaf;
        int n;
        T keys[M - 1];
        Node *children[M];
    };

    Node *root;

    const Node * search(const Node *node, const T& info) const
    {
        if (node == nullptr)
            return node;
        
        auto i = std::lower_bound(node->keys, node->keys + node->n, info)
            - node->keys;

        if (i == node->n or node->keys[i] > info)
            return search(node->children[i], info);

        return node;
    }

public:
    BTree() : root(nullptr) {}

    // Complexidade O(N\log N\log M)
    bool search(const T& info) const
    {
        return search(root, info) != nullptr;
    }

};

int main()
{
    BTree<int, 5> btree;

    auto ok = btree.search(10);
    std::cout << ok << '\n';            // ok = false

    return 0;
}
