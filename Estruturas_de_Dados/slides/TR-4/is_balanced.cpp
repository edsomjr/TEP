template<typename T>
class BinaryTree {
private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    int heigth(const Node *node) const
    {
        if (node == nullptr)
            return 0;
        
        return std::max(heigth(node->left), heigth(node->right)) + 1;
    }

    bool is_balanced(const Node *node) const
    {
        if (node == nullptr)
            return true;
        
        int L = heigth(node->left);
        int R = heigth(node->right);
        
        if (abs(L - R) > 1)
            return false;
        
        return is_balanced(node->left) and is_balanced(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    bool is_balanced() const { return is_balanced(root); }
};
