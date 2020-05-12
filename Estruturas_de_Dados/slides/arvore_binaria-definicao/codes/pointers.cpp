template<typename T>
class BinaryTree {
private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

public:
    BinaryTree() : root(nullptr) {}
};
