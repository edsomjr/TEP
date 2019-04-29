#include <bits/stdc++.h>

using namespace std;

template<typename T, size_t M>
class BTree {
private:
    struct Node {
        bool leaf;
        Node *parent;
        vector<T> keys;
        vector<Node *> children;

        Node(bool is_leaf = true) : leaf(is_leaf), parent(nullptr) {}
    };

    Node *root;

public:
    // A árvore é inicializada com um nó sem nenhuma chave armazenada
    BTree() : root(new Node()) {}

    // Complexidade O(log N log M)
    bool search(const T& info) const
    {
        auto node = search(root, info);

        return binary_search(node->keys.begin(), node->keys.end(), info);
    }

private:
    // Procura pelo nó onde a informação deveria estar
    Node * search(Node *node, const T& info) const
    {
        if (node->leaf)
            return node;

        auto i = lower_bound(node->keys.begin(), node->keys.end(), info)
            - node->keys.begin();

        return search(node->children[i], info);
    }

public:
    bool insert(const T& info)
    {
        // Não insere informações duplicadas
        if (search(info))
            return false;

        auto node = search(root, info);
        return insert(info, node);
    }

private:
    bool insert(const T& info, Node *node, Node* child = nullptr)
    {
        auto child_compare = [](const Node *a, const Node *b)
            {
                if (a->keys.empty())
                    return false;

                if (b->keys.empty())
                    return true;

                return a->keys[0] < b->keys[0];
            };

        node->keys.push_back(info);
        sort(node->keys.begin(), node->keys.end());

        if (child)
        {
            node->children.push_back(child);
            sort(node->children.begin(), node->children.end(),
                child_compare);
        }

        // Capacidade do nó superada: o nó deve ser dividido
        if (node->keys.size() == M)
        {
            auto S = new Node(node->leaf);
            auto half = M/2;

            // Divide as chaves
            for (size_t i = half; i < M; ++i)
            {
                S->keys.push_back(node->keys.back());
                node->keys.pop_back();
            }

            reverse(S->keys.begin(), S->keys.end());

            // Determina o elemento do meio, que subirá para o pai
            auto new_info = node->keys.back();
            node->keys.pop_back();

            // Divide os filhos, se necessário
            if (node->leaf == false)
            {
                for (size_t i = 0; i <= S->keys.size(); ++i)
                {
                    S->children.push_back(node->children.back());
                    node->children.pop_back();
                }

                reverse(S->children.begin(), S->children.end());
            }
        
            if (node->parent)
            {
                S->parent = node->parent;
                return insert(new_info, node->parent, S);
            } else
            {
                root = new Node(false);
                root->keys.push_back(new_info);
                root->children.push_back(node);
                root->children.push_back(S);

                node->parent = root;
                S->parent = root;
            }
        } 

        return true;
    }

    friend ostream& operator<<(ostream& os, const BTree& bt)
    {
        using ni = pair<BTree::Node *, int>;

        queue<ni> q;
        int h = 0;

        if (bt.root)
            q.push(ni(bt.root, 0));

        while (not q.empty())
        {
            auto p = q.front();
            q.pop();

            auto node = p.first;
            auto level = p.second;

            if (level > h)
            {
                os << '\n';
                h = level;
            }

            os << "[";

            for (size_t i = 0; i < M - 1; ++i)
            {
                if (i)
                    os << "|";

                if (i < node->keys.size())
                    os << " " << node->keys[i] << " ";
                else
                    os << "   ";
            }

            os << "]";

            for (const auto& child : node->children)
                q.push(ni(child, level + 1));
        }

        return os;
    }
};

int main()
{
    BTree<int, 4> btree;

    auto ok = btree.search(10);
    cout << ok << '\n';            // ok = false

    const vector<int>& xs { 50, 80, 30, 42, 99, 17, 25, 67, 61, 45, 92, 29, 63 };

    for (const auto& x : xs)
    {
        cout << "Inserindo " << x << "\n";
        btree.insert(x);
        cout << btree << "\n\n";
    }

    return 0;
}

/*template<typename T>
void print_vector(const vector<T>& xs, size_t M)
{
    for (size_t i = 0; i < M - 1; ++i)
    {
        if (i)
            cout << "|";

        if (i < xs.size())
            cout << " " << xs[i] << " ";
        else
            cout << "   ";
    }

    cout << "]\n";
}
*/
