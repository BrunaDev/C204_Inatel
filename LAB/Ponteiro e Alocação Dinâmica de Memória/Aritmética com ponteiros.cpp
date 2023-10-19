#include <iostream>

using namespace std;

int* vezes(int *a, int *b) {
    int *resultado = new int; // Aloca mem�ria dinamicamente para o resultado
    *resultado = (*a) * (*b); // Realiza a multiplica��o e armazena o resultado na mem�ria alocada
    return resultado; // Retorna o ponteiro para o resultado
}

int main() {
    int x, y;
    cout << "Digite dois numeros inteiros: ";
    cin >> x >> y;

    int *ptrResultado = vezes(&x, &y); // Chama a fun��o e recebe o ponteiro para o resultado

    cout << "O resultado da multiplica��o e: " << *ptrResultado << endl;

    // Libera a mem�ria alocada dinamicamente
    delete ptrResultado;

    return 0;
}