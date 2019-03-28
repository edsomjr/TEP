#include <functional>

template<typename T>
class BST {
private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    void preorder(Node *node, function<void(Node *)>& visit)
    {
        if (node)
        {
            visit(node);
            preorder(node->left, visit);
            preorder(node->right, visit);
        }
    }

    void inorder(Node *node, function<void(Node *)>& visit)
    {
        if (node)
        {
            inorder(node->left, visit);
            visit(node);
            inorder(node->right, visit);
        }
    }

    void postorder(Node *node, function<void(Node *)>& visit)
    {
        if (node)
        {
            postorder(node->left, visit);
            postorder(node->right, visit);
            visit(node);
        }
    }
};
