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

        C->parent = G;
        P->parent = C;

        if (C->left)
            C->left->parent = P;
    }

    void rotate_right(Node *G, Node *P, Node *C)
    {
        if (G != nullptr) 
            G->left == P ? G->left = C : G->right = C;
        
        P->left = C->right;
        C->right = P;

        C->parent = G;
        P->parent = C;

        if (C->right)
            C->right->parent = P;
    }

public:
    void insert(const T& info) {
        auto node = insert(&root, nullptr, info);
        restore_properties(node);
    }

private:
    Node * insert(Node **node, Node *parent, const T& info)
    {
        if (*node == nullptr) {
            *node = new Node { info, Node::RED, nullptr, nullptr, parent };
            return *node;
        }

        if ((*node)->info == info)
            return *node;
        else if (info < (*node)->info)
            return insert(&(*node)->left, *node, info);
        else
            return insert(&(*node)->right, *node, info);
    }

    void restore_properties(Node *node)
    {
        if (parent(node) == nullptr)        // Cenário A: node é a raiz
            node->color = Node::BLACK;
        else if (parent(node)->color == Node::BLACK)    // Cenário B
            return;
        else if (uncle(node) and uncle(node)->color == Node::RED)
        {
            // Cenário C: pai e tio vermelhos
            parent(node)->color = Node::BLACK;
            uncle(node)->color = Node::BLACK;
            grandparent(node)->color = Node::RED;

            // Como o pai é vermelho, o avô não é nulo
            restore_properties(grandparent(node));
        } else
        {
            // Cenário D: pai vermelho, tio preto
            auto C = node;
            auto P = parent(node);
            auto G = grandparent(node);

            if (C == P->right and P == G->left)
            {
                rotate_left(G, P, C);
                P = C;
            } else if (node == P->left and P == G->right)
            {
                rotate_right(G, P, C);
                P = C;
            }

            C = P;
            P = G;
            G = parent(P);

            if (C == P->left)
                rotate_right(G, P, C);
            else
                rotate_left(G, P, C);

            // Corner case: após a rotação C é a nova raiz
            if (G == nullptr)
                root = C;

            C->color = Node::BLACK;
            P->color = Node::RED;
        }
    }

    void preorder(std::ostream& os, const Node* node) const
    {
        if (node)
        {
            os << node->info << " (" << (node->color == Node::RED ? "R" : "B") << ") ";
            preorder(os, node->left);
            preorder(os, node->right);
        }
    }

    void inorder(std::ostream& os, const Node* node) const
    {
        if (node)
        {
            inorder(os, node->left);
            os << node->info << " (" << (node->color == Node::RED ? "R" : "B") << ") ";
            inorder(os, node->right);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const RBTree& tree)
    {
        tree.preorder(os, tree.root);
        os << '\n';

        tree.inorder(os, tree.root);
        os << '\n';

        return os;
    }
};

int main()
{
    RBTree<int> tree;
    std::vector<int> xs { 40, 17, 88, 91, 96, 25, 23 };

    for (const auto& x : xs)
    {
        tree.insert(x);
        std::cout << tree << '\n';
    }

    return 0;
}
