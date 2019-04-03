template<typename T>
class BST {
private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    void balanced_insertion(BST *tree, const vector<T>& vs, int a, int b)
    {
        if (a <= b) 
        {
            int m = a + (b - a)/2;

            tree->insert(vs[m]);
            balanced_insertion(tree, vs, a, m - 1);
            balanced_insertion(tree, vs, m + 1, b);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(const T& info);

    static BinaryTree * balanced(const std::vector<T>& xs)
    {
        std::vector<T> vs(xs);
        std::sort(vs.begin(), vs.end());

        BST *tree = new BST();
        balanced_insertion(tree, vs, 0, vs.size() - 1);

        return tree;
    }    
};
