#include <iostream>

struct BST {
    struct Node {
        int info;
        Node *left, *right;
    };

    Node *root;

    BST() : root(nullptr) {}

    void inorder(const Node* node) const
    {
        if (node) {
            inorder(node->left);
            std::cout << ' ' << node->info;
            inorder(node->right);
        }
    }

    void preorder(const Node* node) const
    {
        if (node)
        {
            std::cout << ' ' << node->info;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(const Node* node) const
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            std::cout << ' ' << node->info;
        }
    }

    void insert(int info)
    {
        Node **node = &root;
        
        while (*node)
        {
            if ((*node)->info == info)
                return;
            else if (info < (*node)->info)
                node = &(*node)->left;
            else
                node = &(*node)->right;
        }
        
        *node = new Node { info, nullptr, nullptr };
    }
};

int main()
{
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;

    for (int test = 1; test <= C; ++test)
    {
        int N;
        std::cin >> N;

        BST tree;

        while (N--) {
            int info;
            std::cin >> info;

            tree.insert(info);
        }

        std::cout << "Case " << test << ":\n";

        std::cout << "Pre.:";
        tree.preorder(tree.root);
        std::cout << "\n";

        std::cout << "In..:";
        tree.inorder(tree.root);
        std::cout << "\n";

        std::cout << "Post:";
        tree.postorder(tree.root);
        std::cout << "\n\n";
   }

   return 0;
}
