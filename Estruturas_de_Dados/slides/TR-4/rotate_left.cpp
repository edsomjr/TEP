// C deve ser o filho à direita de P
void rotate_left(Node *G, Node *P, Node *C)
{
    // Se P não é a raiz da árvore
    if (G != nullptr) 
    {
        // Então o avô se torna pai do neto
        if (G->left == P)
            G->left = C;
        else  
            G->right = C;
    }
    
    // A subárvore à esquerda do filho se 
    // torna a subárvore à direita do pai
    P->right = C->left;
    
    // O pai se torna o filho esquerdo do neto
    C->left = P;
}
