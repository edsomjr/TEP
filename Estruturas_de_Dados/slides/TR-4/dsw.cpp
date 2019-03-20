template<typename T>
class BST {
public:
    BST() : root(nullptr) {}

    void DSW()
    {
        backbone();
        
        int n = size();
        int m = (1 << ((int) floor(log(n+1)/log(2)))) - 1;

        // n - m = folhas que não estão na árvore completa
        transform(n - m);       
        
        while (m > 1)
        {
            m = m/2;
            transform(m);
        }
    }

private:
    struct Node {
        T info;
        Node *left, *right;
    };

    Node *root;

    void transform(int qtd)
    {
        Node *G = nullptr, *P = nullptr, *C = nullptr;
        
        while (qtd--)
        {
            for (j = 0; j <= 1; j++)
            {
                // Atualiza o pai e o avô
                G = P;
                P = C;
                
                // Define o filho
                if (C)
                    C = C->right;
                else if (P == nullptr)
                    C = root;
            }
            
            // Atualiza o root, quando necessário
            if (P == root)
                root = C;

            rotate_left(G, P, C);
        }
    }

};
