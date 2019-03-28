#include <bits/stdc++.h>

template<typename T>
class RBTree {
private:
    struct Node {
        T info;
        enum { RED, BLACK } color;
        Node *left, *right, *parent;
    };

    Node *root;

public:
    RBTree() : root(nullptr) {}

private:
    Node * parent(Node *node)
    {
        return node ? node->parent : nullptr;
    }

    Node * grandparent(Node* node)
    {
        return parent(parent(node));
    }

    Node* sibling(Node* node)
    {
        auto p = parent(node);
        return p ? (node == p->left ? p->right : p->left) : nullptr;
    }

    Node * uncle(Node* node)
    {
        return sibling(parent(node));
    } 

    void rotate_left(Node *G, Node *P, Node *C)
    {
        if (G != nullptr) 
            G->left == P ? G->left = C : G->right = C;
        
        P->right = C->left;
        C->left = P;
    }

    void rotate_right(Node *G, Node *P, Node *C)
    {
        if (G != nullptr) 
            G->left == P ? G->left = C : G->right = C;
        
        P->left = C->right;
        C->right = P;
    }

};

int main()
{
    RBTree<int> tree;

/*    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    std::cout << tree << '\n';
    std::cout << tree.size() << '\n';
    tree.erase(4);

    std::cout << tree << '\n';
    std::cout << tree.size() << '\n'; */
    return 0;
}
