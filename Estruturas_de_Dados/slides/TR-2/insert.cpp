#include <iostream>
#include <functional>

template<typename T>
class BST {
    friend std::ostream& operator<<(std::ostream& os, const BST& tree)
    {
        tree.preorder(tree.root, 
            [&](T value) { os << "[" << value << "] "; });

        return os;
    }

private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    void inorder(const Node* node, const std::function<void(T)>& f) const
    {
        if (node)
        {
            inorder(node->left, f);
            f(node->info);
            inorder(node->right, f);
        }
    }

    void preorder(const Node* node, const std::function<void(T)>& f) const
    {
        if (node)
        {
            f(node->info);
            inorder(node->left, f);
            inorder(node->right, f);
        }
    }

    void postorder(const Node* node, const std::function<void(T)>& f) const
    {
        if (node)
        {
            inorder(node->left, f);
            inorder(node->right, f);
            f(node->info);
        }
    }


public:
    BST() : root(nullptr) {}

    void insert(const T& info)
    {
        Node *node = root, *prev = nullptr;
        
        while (node)
        {
            prev = node;
            
            if (node->info == info)
                return;
            else if (info < node->info)
                node = node->left;
            else
                node = node->right;
        }
        
        node = new Node { info, nullptr, nullptr };

        if (!root)
            root = node;
        else if (info < prev->info)
            prev->left = node;
        else 
            prev->right = node;
    }
};

int main()
{
    BST<int> tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(3);

    std::cout << tree << '\n';

    return 0;
}
