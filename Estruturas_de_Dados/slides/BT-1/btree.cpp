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

        void sort_keys()
        {
            sort(keys.begin(), keys.end());
        }

        void sort_children()
        {
            sort(children.begin(), children.end(), 
                [](const Node *a, const Node *b) {
                    if (a->keys.empty())
                        return false;

                    if (b->keys.empty())
                        return true;

                    return a->keys[0] < b->keys[0];
                });
        }

        // Índice da menor chave maior ou igual a key
        size_t index(const T& key) const
        {
            auto it = lower_bound(keys.begin(), keys.end(), key);
            return it - keys.begin();
        }
    };

    Node *root;

public:
    // A árvore é inicializada com um nó sem nenhuma chave armazenada
    BTree() : root(new Node()) {}

    // Complexidade O(log N log M)
    bool find(const T& info) const
    {
        auto node = find(root, info);

        return binary_search(node->keys.begin(), node->keys.end(), info);
    }

private:
    // Procura pelo nó onde a informação deveria estar
    Node * find(Node *node, const T& info) const
    {
        if (node->leaf)
            return node;

        auto i = node->index(info);

        if (i < node->keys.size() and node->keys[i] == info)
            return node;

        return find(node->children[i], info);
    }

public:
    bool insert(const T& info)
    {
        // Não insere informações duplicadas
        if (find(info))
            return false;

        auto node = find(root, info);

        return insert(info, node);
    }

private:
    bool insert(const T& info, Node *node, Node* child = nullptr)
    {
        // Insere a informação e o filho
        node->keys.push_back(info);
        node->sort_keys();

        if (child)
        {
            node->children.push_back(child);
            node->sort_children();
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
                    S->children.back()->parent = S;
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

public:
    bool erase(const T& info)
    {
        // Não remove informações inexistentes
        if (not find(info))
            return false;

        auto node = find(root, info);
        erase(info, node);

        return true;
    }

private:
 
    void erase(const T& info, Node *node)
    {
        if (node->leaf == false) // Remoção por cópia
        {
            auto i = node->index(info);
            auto temp = node;

            // Procura pelo filho mais à direita da sub-árvore à esquerda
            while (not temp->leaf)
            {
                auto k = temp->index(info);
                temp = temp->children[k];
            }

            auto j = temp->index(info) - 1;

            // Troca os nós
            swap(node->keys[i], temp->keys[j]);

            // Prossegue a remoção na folha
            node = temp;
        }

        // Elimina a chave 
        auto it = lower_bound(node->keys.begin(), node->keys.end(), info);

        node->keys.erase(it);
        node->sort_keys();

        // Se o nó for a raiz ou houver chaves o suficiente, nada a fazer
        auto P = node->parent;
        auto limit = (M + 1)/2 - 1;

        if (not P or node->keys.size() >= limit)
            return;

        // Irmãos
        auto i = P->index(info);    // node é o filho i

        auto R = i == M ? nullptr : P->children[i + 1];
        auto L = i ? P->children[i - 1] : nullptr;

        // Caso 1.1
        if (L and L->keys.size() > limit)
        {
            node->keys.push_back(P->keys[i - 1]);
            node->sort_keys();

            P->keys[i - 1] = L->keys.back();
            L->keys.pop_back();

            return;
        }

        if (R and R->keys.size() > limit)
        {
            node->keys.push_back(P->keys[i]);
            node->sort_keys();

            P->keys[i] = R->keys.front();
            R->keys[0] = R->keys.back();
            R->keys.pop_back();

            R->sort_keys();

            return;
        }

        // Caso 2
        auto N = L ? L : R;
        auto k = L ? i - 1 : i;

        while (not N->keys.empty())
        {
            node->keys.push_back(N->keys.back());
            N->keys.pop_back();
        }

        node->keys.push_back(P->keys[k]);
        node->sort_keys();

        P->keys[k] = P->keys.back();
        P->keys.pop_back();

        P->sort_keys();
        P->sort_children();

        delete P->children.back();
        P->children.pop_back();
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

            os << "] (";

            auto P = node->parent;

            if (P)
                cout << P->keys[0];
            else
                cout << "-";

            os << ", " << (node->leaf ? 'S' : 'N') << ") ";

            for (const auto& child : node->children)
                q.push(ni(child, level + 1));
        }

        return os;
    }
};

int main()
{
    BTree<int, 4> btree;

    auto ok = btree.find(10);
    cout << ok << '\n';            // ok = false

    const vector<int> xs { 50, 80, 30, 42, 99, 17, 25, 67, 61, 45, 92, 29, 63 };

    for (const auto& x : xs)
    {
        cout << "Inserindo " << x << "\n";
        btree.insert(x);
        cout << btree << "\n\n";
    }

    const vector<int> ys { 61, 63, 99, 67, 42 };

    for (const auto& y : ys)
    {
        cout << "Removendo " << y << "\n";
        btree.erase(y);
        cout << btree << "\n\n";
    }

    return 0;
}
