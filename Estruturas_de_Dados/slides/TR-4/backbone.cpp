template<typename T>
class BST {
public:
    BST() : root(nullptr) {}

private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    void backbone()
    {
        Node *C = root, P = nullptr, G = nullptr;

        while (C != nullptr)
        {
            if (C->left) {
                if (C == root)
                    root = C->left;

                P = C;
                C = C->left;
                rotate_right(G, P, C);
            } 
            else {
                G = C;
                C = C->right;
            }
        }
    }
};
