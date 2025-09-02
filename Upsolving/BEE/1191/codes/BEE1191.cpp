#include <iostream>

struct BST {
    struct Node {
        char info;
        Node *left, *right;
    };

    Node *root;

    BST() : root(nullptr) {}

    void postorder(const Node* node) const
    {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->info;
        }
    }

    void insert(char info, const int rank[])
    {
        Node **node = &root;
        
        while (*node)
        {
            if ((*node)->info == info)
                return;
            else if (rank[info - 'A'] < rank[(*node)->info - 'A'])
                node = &(*node)->left;
            else
                node = &(*node)->right;
        }
        
        *node = new Node { info, nullptr, nullptr };
    }
};

int main() {
    std::string preorder, inorder;

    while (std::cin >> preorder >> inorder) {
        int rank[30], nxt = 1;

        for (const auto& c : inorder)
            rank[c - 'A'] = nxt++;

        BST tree;

        for (const auto& c : preorder)
            tree.insert(c, rank);

        tree.postorder(tree.root);
        std::cout << "\n";
   }

   return 0;
}
