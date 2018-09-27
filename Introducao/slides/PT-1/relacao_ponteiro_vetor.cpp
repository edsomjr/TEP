#include <iostream>

using namespace std;

int main() {
    string keywords[] = {"int", "char", "double", "float", "bool", 
        "void", "class"};
    string *p = keywords;

    cout << "Endereco: " << p << ", valor: " << *p << endl;
    cout << "Terceiro elemento do vetor: " << *(p + 2) << endl;

    int matrix[][2] = { {1, 2}, {3,4}, {5,6}, {7,8} };
    int *q = &matrix[0][0], (*r)[2] = matrix;
 
    cout << "Elemento 3x2: via índices = " << matrix[2][1] <<
        ", via ponteiro = " <<  *(*(r + 2) + 1) << ", linearizada = "
        << q[1 + 2*2] << endl;

    return 0;
}
