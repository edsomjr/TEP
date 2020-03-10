#include <iostream>

using namespace std;

#define MAX 1000010

int tree[MAX];

int lor(int a, int b)
{
    return a | b;
}

int lxor(int a, int b)
{
    return a ^ b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int qtd = 1 << n;
    int pos = qtd;

    for (int i = 0; i < qtd; ++i)
        scanf("%d", tree + pos + i);

 /*   for (int i = 1; i < 2*qtd; ++i) 
        printf("%3d", i);
    printf("\n");

    for (int i = 1; i < 2*qtd; ++i) 
        printf("%3d", tree[i]);
    printf("\n");
*/
    pos >>= 1;
    int (*op)(int, int) = lor, (*next)(int, int) = lxor;

    while (pos)
    {
        for (int i = pos; i < 2*pos; ++i)
        {
            tree[i] = op(tree[2*i], tree[2*i + 1]);
        }
        swap(op, next);
        pos >>= 1;
/*    for (int i = 1; i < 2*qtd; ++i) 
        printf("%3d", i);
    printf("\n");

    for (int i = 1; i < 2*qtd; ++i) 
        printf("%3d", tree[i]);
    printf("\n"); */
    }
 
//printf("queries:\n");
    while (m--)
    {
        int p, b;
        scanf("%d %d", &p, &b);
        pos = qtd + p - 1;
//printf("p = %d, b = %d\n", p, b);
        tree[pos] = b;

        int sib = pos % 2 ? pos - 1 : pos + 1;
        int par = pos / 2;

        op = lor;
        next = lxor;

        while (par)
        {
            tree[par] = op(tree[pos], tree[sib]);
//printf("par = %d, tree[%d] = %d, pos = %d, sib = %d\n", par, par, tree[par], pos, sib);
            pos = par;
            sib = par % 2 ? pos - 1 : pos + 1;
            swap(op, next);
            par >>= 1;
        }
 /*    for (int i = 1; i < 2*qtd; ++i) 
        printf("%3d", i);
    printf("\n");

    for (int i = 1; i < 2*qtd; ++i) 
        printf("%3d", tree[i]);
    printf("\n"); */

        printf("%d\n", tree[1]);
    }

    return 0;
}
