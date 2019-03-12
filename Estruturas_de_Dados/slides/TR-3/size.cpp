template<typename T>
class BST {
private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    int size(const Node *node) const
    {
        return node ?  size(node->left) + size(node->right) + 1 : 0;
    }

public:
    BST() : root(nullptr) {}

    int size() const { return size(root); }
};
