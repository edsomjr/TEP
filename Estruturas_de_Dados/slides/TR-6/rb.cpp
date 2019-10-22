#include <bits/stdc++.h>

template<typename T>
class RBTree {
private:
    struct Node {
        T info;
        enum { RED, BLACK } color;
        Node *left, *right, *parent;
    };

    Node *root;

public:
    RBTree() : root(nullptr) {}

private:
    Node * parent(Node *node)
    {
        return node ? node->parent : nullptr;
    }

    Node * grandparent(Node* node)
    {
        return parent(parent(node));
    }

    Node* sibling(Node* node)
    {
        auto p = parent(node);
        return p ? (node == p->left ? p->right : p->left) : nullptr;
    }

    Node * uncle(Node* node)
    {
        return sibling(parent(node));
    } 

    void rotate_left(Node *G, Node *P, Node *C)
    {
        if (G != nullptr) 
            G->left == P ? G->left = C : G->right = C;
 
        P->right = C->left;
        C->left = P;

        C->parent = G;
        P->parent = C;

        if (C->left)
            C->left->parent = P;
    }

    void rotate_right(Node *G, Node *P, Node *C)
    {
        if (G != nullptr) 
            G->left == P ? G->left = C : G->right = C;
        
        P->left = C->right;
        C->right = P;

        C->parent = G;
        P->parent = C;

        if (C->right)
            C->right->parent = P;
    }

public:
    void insert(const T& info) {
        auto node = insert(&root, nullptr, info);
        restore_properties(node);
    }

private:
    Node * insert(Node **node, Node *parent, const T& info)
    {
        if (*node == nullptr) {
            *node = new Node { info, Node::RED, nullptr, nullptr, parent };
            return *node;
        }

        if ((*node)->info == info)
            return *node;
        else if (info < (*node)->info)
            return insert(&(*node)->left, *node, info);
        else
            return insert(&(*node)->right, *node, info);
    }

    void restore_properties(Node *node)
    {
        if (parent(node) == nullptr)        // Cenário A: node é a raiz
            node->color = Node::BLACK;
        else if (parent(node)->color == Node::BLACK)    // Cenário B
            return;
        else if (uncle(node) and uncle(node)->color == Node::RED)
        {
            // Cenário C: pai e tio vermelhos
            parent(node)->color = Node::BLACK;
            uncle(node)->color = Node::BLACK;
            grandparent(node)->color = Node::RED;

            // Como o pai é vermelho, o avô não é nulo
            restore_properties(grandparent(node));
        } else
        {
            // Cenário D: pai vermelho, tio preto
            auto C = node;
            auto P = parent(node);
            auto G = grandparent(node);

            if (C == P->right and P == G->left)
            {
                rotate_left(G, P, C);
                P = C;
            } else if (node == P->left and P == G->right)
            {
                rotate_right(G, P, C);
                P = C;
            }

            C = P;
            P = G;
            G = parent(P);

            if (C == P->left)
                rotate_right(G, P, C);
            else
                rotate_left(G, P, C);

            // Corner case: após a rotação C é a nova raiz
            if (G == nullptr)
                root = C;

            C->color = Node::BLACK;
            P->color = Node::RED;
        }
    }

private:
    Node * find(Node *node, const T& info)
    {
        if (node == nullptr or node->info == info)
            return node;

        return info < node->info ? find(node->left, info) :
            find(node->right, info); 
    }

    // Troca de informação com o nó mais à direita da sub-árvore
    // à esquerda de N, e retorna um ponteiro para D
    Node * swap_info(Node *N)
    {
        auto D = N->left;

        while (D->right)
            D = D->right;

        std::swap(N->info, D->info);
        return D;
    }

    // Troca as posições do pai N e seu filho C
    void swap_nodes(Node *N, Node *C)
    {
        auto P = parent(N);

        if (C)
            C->parent = P;

        if (P == nullptr)
            root = C;
        else if (P->left == N) 
            P->left = C;
        else 
            P->right = C;
    }

public:
    void erase(const T& info)
    {
        Node *N = find(root, info);

        if (N == nullptr)       // Caso trivial
            return;

        // Reduz o caso 3 ao caso 1 ou ao caso 2
        if (N->left and N->right)
            N = swap_info(N);

        erase(N);
    }

private:
    void erase(Node *N)
    {
        // As relações de parentesco devem ser determinadas
        // antes da troca de N por C

        auto P = parent(N);
        auto S = sibling(N);
        auto C = N->left ? N->left : N->right;

        swap_nodes(N, C);

        // Se N é vermelho não há nada mais a fazer

        if (N->color == Node::BLACK)
        {
            // N é preto e o filho não-folha C é vermelho
            if (C and C->color == Node::RED)
                C->color = Node::BLACK;
            else
                rebalancing(P, S, C);
        }

        delete N;
    }

    void rebalancing(Node *P, Node *S, Node *N)
    {
        // N é a raiz da árvore
        if (P == nullptr)
            return;

        // N tem irmão S vermelho: este caso não se encerra no if
        if (S and S->color == Node::RED)
        {
            P->color = Node::RED;
            S->color = Node::BLACK;

            if (N == P->left)
                rotate_left(grandparent(S), P, S);
            else
                rotate_right(grandparent(S), P, S);

            if (parent(S) == nullptr)
                root = S;

            // O irmão deve ser atualizado neste cenário
            S = P->left == N ? P->right : P->left;
        }

        // N tem irmão, pai e sobrinhos pretos
        if (P and P->color == Node::BLACK and S->color == Node::BLACK
            and (S->left == nullptr or S->left->color == Node::BLACK)
            and (S->right == nullptr or S->right->color == Node::BLACK))
        {
            S->color = Node::RED;
            return rebalancing(parent(P), sibling(P), P);
        }

        // N tem irmão e sobrinhos pretos, pai vermelho
        if (P and P->color == Node::RED and S->color == Node::BLACK
            and (S->left == nullptr or S->left->color == Node::BLACK)
            and (S->right == nullptr or S->right->color == Node::BLACK))
        {
            S->color = Node::RED;
            P->color = Node::BLACK;
            return;
        }

        // N tem irmão preto com sobrinho à esquerda vermelho
        if (S and S->color == Node::BLACK)
        {
            if (P and P->left == N 
                and (S->left or S->left->color == Node::RED) and
                (S->right == nullptr or S->right->color == Node::BLACK))
            {
                S->color = Node::RED;
                S->left->color = Node::BLACK;
                rotate_right(P, S, S->left);
                S = P->right;
            } else if (P and P->right == N
                and (S->left == nullptr or S->left->color == Node::BLACK)
                and (S->right or S->right->color == Node::RED))
            {
                S->color = Node::RED;
                S->right->color = Node::BLACK;
                rotate_left(P, S, S->right);
                S = P->left;
            }
        }

        // N tem irmão preto com sobrinho à direita vermelho
        S->color = P->color;
        P->color = Node::BLACK;

        if (N == P->left)
        {
            S->right->color = Node::BLACK;
            rotate_left(grandparent(P), P, S);
        } else
        {
            S->left->color = Node::BLACK;
            rotate_right(grandparent(P), P, S);
        }

        if (parent(S) == nullptr)
            root = S;
    }

    void preorder(std::ostream& os, const Node* node) const
    {
        if (node)
        {
            os << node->info << " (" << (node->color == Node::RED ? "R" : "B") << ") ";
            preorder(os, node->left);
            preorder(os, node->right);
        }
    }

    void inorder(std::ostream& os, const Node* node) const
    {
        if (node)
        {
            inorder(os, node->left);
            os << node->info << " (" << (node->color == Node::RED ? "R" : "B") << ") ";
            inorder(os, node->right);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const RBTree& tree)
    {
        tree.preorder(os, tree.root);
        os << '\n';

        tree.inorder(os, tree.root);
        os << '\n';

        return os;
    }
};

int main()
{
    RBTree<int> tree;
    std::vector<int> xs { 40, 18, 75 };

    for (const auto& x : xs)
        tree.insert(x);

    std::cout << "Árvore:\n" << tree << '\n';

    std::cout << "Caso trivial:\n";
    tree.erase(45);
    std::cout << tree << '\n';

    std::cout << "Remoção de nó vermelho\n";
    tree.erase(40);
    std::cout << tree << '\n';

    xs = std::vector<int> { 4, 51, 92, 60 };

    for (const auto& x : xs)
        tree.insert(x);

    std::cout << "Nova árvore:\n" << tree << '\n';

    std::cout << "Remoção de nó preto com filho vermelho\n";
    tree.erase(51);
    std::cout << tree << '\n';

    RBTree<int> tree2;
    tree2.insert(18);

    std::cout << "Nova árvore:\n" << tree2 << '\n';

    std::cout << "Remoção de nó raiz com filhos pretos\n";
    tree2.erase(18);
    std::cout << tree2 << '\n';

   xs = std::vector<int> { 40, 75, 18, 4, 22, 9 };

    for (const auto& x : xs)
        tree2.insert(x);

    std::cout << "Nova árvore:\n" << tree2 << '\n';

    std::cout << "Remoção de nó preto com irmão vermelho\n";
    tree2.erase(75);
    std::cout << tree2 << '\n';

    xs = std::vector<int> { 40, 18, 88, 91, 4 };
    RBTree<int> tree3;

    for (const auto& x : xs)
        tree3.insert(x);

    tree3.erase(4);
    tree3.erase(91);

    std::cout << "Nova árvore:\n" << tree3 << '\n';

    std::cout << "Remoção de nó com pai preto e irmão e sobrinhos pretos\n";
    tree3.erase(88);
    std::cout << tree3 << '\n';

    xs = std::vector<int> { 18, 4, 40, 88, 1, 10, 7 };
    RBTree<int> tree4;

    for (const auto& x : xs)
        tree4.insert(x);

    tree4.erase(7);
    std::cout << "Nova árvore:\n" << tree4 << '\n';

    std::cout << "Remoção de nó com pai vermelho e irmão e sobrinhos pretos\n";
    tree4.erase(10);
    std::cout << tree4 << '\n';

    xs = std::vector<int> { 40, 17, 88, 56 };
    RBTree<int> tree5;

    for (const auto& x : xs)
        tree5.insert(x);

    std::cout << "Nova árvore:\n" << tree5 << '\n';

    std::cout << "Remoção de nó com irmão preto e sobrinho à esquerda vermelho\n";
    tree5.erase(17);
    std::cout << tree5 << '\n';

    return 0;
}
