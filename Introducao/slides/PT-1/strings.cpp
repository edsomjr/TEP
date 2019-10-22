#include <iostream>
#include <string>

using namespace std;

int main()
{
	string texto = "Estruturas de Dados e " "Algoritmos";

	cout << "Numero de caracteres: " << texto.size() << endl;
		
	cout << "Decimo primeiro caractere: " << texto[10] << endl;

	int size = 0;

	for (const char *c = texto.c_str(); *c; size++, c++);

	cout << "Numero de caracteres contabilizados: " << size << endl;

	return 0;
}

