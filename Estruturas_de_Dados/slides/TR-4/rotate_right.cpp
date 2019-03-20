// C deve ser o filho à esquerda de P
void rotate_right(Node *G, Node *P, Node *C)
{
    // Se P não é a raiz da árvore
    if (G != NULL) 
    {
        // Então o avô se torna pai do neto
        if (G->left == P)
            G->left = C;
        else 
            G->right = C;
    }
    
    // A subárvore à direita do filho 
    // se torna a subárvore à esquerda do pai
    P->left = C->right;
    
    // O pai se torna o filho à direita do neto
    C->right = P;
}
