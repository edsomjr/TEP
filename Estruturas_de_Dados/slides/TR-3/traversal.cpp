#include <funcional>

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
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node *node, function<void(Node *)>& visit)
    {
        if (node)
        {
            inorder(node->left);
            visit(node);
            inorder(node->right);
        }
    }

    void postorder(Node *node, function<void(Node *)>& visit)
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            visit(node);
        }
    }
};
