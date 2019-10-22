template<typename T>
class BST {
private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    bool search(Node *node, const T& info) const
    {
        while (node)
        {
            if (info == node->info)
                return true;
            else if (info < node->info)
                node = node->left;
            else 
                node = node->right;
        }
        
        return false;
    }

public:
    BST() : root(nullptr) {}

    bool search(const T& info) const { return search(root, info); }
};
