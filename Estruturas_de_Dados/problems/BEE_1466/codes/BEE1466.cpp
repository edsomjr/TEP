#include <bits/stdc++.h>

using namespace std;

struct BST {
    struct Node
    {
        int info;
        Node *left, *right;
    };

    Node *root;

    BST() : root(nullptr) {}

    void BFS() const 
    {
        vector<int> xs;
        queue<Node *> q;
        q.push(root);

        while (not q.empty()) {
            auto node = q.front();
            q.pop();

            if (node) {
                xs.push_back(node->info);
                q.push(node->left); 
                q.push(node->right); 
            }
        }

        for (size_t i = 0; i < xs.size(); ++i)
            cout << xs[i] << (i + 1 == xs.size() ? '\n' : ' ');
        cout << '\n';
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
    ios::sync_with_stdio(false);

    int C;
    cin >> C;

    for (int test = 1; test <= C; ++test)
    {
        int N;
        cin >> N;

        BST tree;

        while (N--)
        {
            int info;
            cin >> info;
            tree.insert(info);
        }

        cout << "Case " << test << ":\n";
        tree.BFS();
   }

   return 0;
}
