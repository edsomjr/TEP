template<typename T>
class BST {
private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    void delete_by_copying(Node** n)
    {
        auto node = *n;
        
        if (node == nullptr) return;
        
        if (node->right == nullptr)         // Casos 1 e 2
            *n = node->left;
        else if (node->left == nullptr)     // Caso 2
            *n = node->right;
        else {                              // Caso 3
            auto temp = &(*n)->left;              
            
            while ((*temp)->right)
                temp = &(*temp)->right;
            
            node->info = (*temp)->info;
            return delete_by_copying(temp);
        }
        
        delete node;
    }


public:
    BST() : root(nullptr) {}

    void erase(const T& info)
    {
        Node** node = &root;
        
        while (*node)
        {
            if ((*node)->info == info)
                break;
            
            if (info < (*node)->info)
                node = &(*node)->left;
            else 
                node = &(*node)->right;
        }
        
        delete_by_copying(node);
    }
};
