#include <iostream>
#include <cstdlib>

int* novo_jogo(int N) {
    int *ns = new int[N];

    if (!ns) return nullptr;

    for (int i = 0; i < N; i++) {
        ns[i] = (rand() % 60) + 1;
        
        for (int j = 0; j < i; j++) {
            if (ns[j] == ns[i]) {
                i--;
                break;
            }
        }
    }

    return ns;
}

int main() {
    srand(time(NULL));
    int N;

    do {
        printf("Quantos numeros serão sorteados (entre 6 e 15)? ");
        std::cin >> N;
    } while (N < 6 || N > 15);
    
    auto ns = novo_jogo(N);
    
    if (ns) {
        std::cout << "Numeros sorteados: ";
        for (int i = 0; i < N; i++)
            printf("%d%c", ns[i], " \n"[i + 1 == N]);
        
        delete [] ns;
    }

    return 0;
}
