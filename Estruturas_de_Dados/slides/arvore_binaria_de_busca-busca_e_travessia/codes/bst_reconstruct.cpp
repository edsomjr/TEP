#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
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
            preorder(node->left, f);
            preorder(node->right, f);
        }
    }

    void postorder(const Node* node, const std::function<void(T)>& f) const
    {
        if (node)
        {
            postorder(node->left, f);
            postorder(node->right, f);
            f(node->info);
        }
    }


public:
    BST() : root(nullptr) {}
    BST(const std::vector<T> &preorder, const std::vector<T> &inorder) : root(nullptr)
    {
        insert(preorder[0]);
        int n = preorder.size();
        std::unordered_map<T, int> pos;
        for(int i = 0; i < n; ++i)
          pos[inorder[i]] = i;
        for(int i = 1; i < n; ++i)
        {
            T toinsert = preorder[i];
            int toinsert_pos = pos[preorder[i]];
            Node *node = root;
            Node *prev = nullptr;
            bool left = false;
            std::cerr << "Pra  inserir : " << toinsert << '\n';
            while(node)
            { 
                std::cerr << "    Atual : " << node->info << '\n';
                prev = node;
                int node_pos = pos[node->info];
                std::cerr << "    nodepos: " << node_pos << " toinsertpos: " << toinsert_pos << '\n';
                if(toinsert_pos < node_pos)
                {
                    std::cerr << "    indo esquerda \n";
                    node = node->left, left=true;
                }
                else
                {
                    std::cerr << "    indo direita\n";
                    node = node->right, left=false;;
                }

            }

            Node *newnode = new Node { toinsert, nullptr, nullptr };
            if(left)
                prev->left = newnode;
            else 
                prev->right = newnode;
        }
    }
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

    void preorder(const std::function<void(T)> &f) { preorder(root, f); }
    void postorder(const std::function<void(T)> &f) { postorder(root, f); }
    void inorder(const std::function<void(T)> &f) { inorder(root, f); }

};


void foo(char c) {
  std::cout << c << ' ';
}
int main()
{

    // exemplo do slide.
    std::vector<char> preorder {'A', 'B', 'C', 'D', 'E', 'F'};
    std::vector<char> inorder {'B', 'C', 'A', 'E', 'D', 'F'};
    BST<char> tree (preorder, inorder);

    std::cout << "Preorder:";  tree.preorder(foo); std::cout << '\n';
    std::cout<< "Inorder: ";   tree.inorder(foo); std::cout << '\n';
    std::cout << "Postorder:"; tree.postorder(foo); std::cout << '\n';

    return 0;
}
