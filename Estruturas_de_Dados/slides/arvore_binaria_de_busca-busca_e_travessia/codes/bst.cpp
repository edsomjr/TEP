#include <iostream>
#include <queue>
#include <functional>

template<typename T>
class BST {
    friend std::ostream& operator<<(std::ostream& os, const BST& tree)
    {
        tree.bfs(tree.root);
        return os;
    }

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


    void bfs(Node *node) const
    {
        using pi = std::pair<Node *, int>;
        std::queue<pi> q;
        q.push(pi(node, 0));

        int level = 0;

        while (not q.empty())
        {
            auto x = q.front();
            q.pop();

            auto n = x.first;
            auto i = x.second;

            if (i > level)
            {
                std::cout << '\n';
                level = i;
            }

            if (n == nullptr)
            {
                std::cout << "[x]";
            } else
            {
                std::cout << "[" << n->info << "]";

                q.push(pi(n->left, i + 1));
                q.push(pi(n->right, i + 1));
            }
        }
    }

    void delete_by_merging(Node** n)
    {
        auto node = *n;
        
        if (node == nullptr) return;
        
        if (node->right == nullptr)         // Casos 1 e 2
        {
            std::cout << "Casos 1 e 2, node = " << n << '\n';
            *n = node->left;
        } else if (node->left == nullptr)     // Caso 2
        {
            std::cout << "Caso 2, node = " << n << '\n';
            *n = node->right;
        } else {                              // Caso 3
            std::cout << "Caso 3, node = " << n << '\n';
            auto temp = node->left;              
            
            while (temp->right)
                temp = temp->right;
            
            temp->right = node->right;
            *n = node->left;
        }
        
        delete node;
    }

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
            
std::cout << "Info = " << node->info << ", temp = " << (*temp)->info << '\n';
            node->info = (*temp)->info;
            return delete_by_copying(temp);
        }
        
        delete node;
    }


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

    int size() const { return size(root); }

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

std::cout << "Inserting " << info << " (" << node << ") na posicao ";
        if (!root)
        {
std::cout << &root << '\n';
            root = node;
        } else if (info < prev->info)
        {
std::cout << &prev->left << '\n';
            prev->left = node;
        } else 
        {
std::cout << &prev->right << '\n';
            prev->right = node;
        }
    }

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
        
std::cout << "Erase node on address " << node << " (" << *node << ")\n";
//        delete_by_merging(node);
        delete_by_copying(node);
    }

};

int main()
{
    BST<int> tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

    std::cout << tree << '\n';
    std::cout << tree.size() << '\n';
    tree.erase(4);

    std::cout << tree << '\n';
    std::cout << tree.size() << '\n';
    return 0;
}
