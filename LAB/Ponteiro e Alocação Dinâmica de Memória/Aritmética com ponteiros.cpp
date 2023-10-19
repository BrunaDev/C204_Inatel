#include <iostream>

using namespace std;

int* vezes(int *a, int *b) {
    int *resultado = new int; // Aloca memória dinamicamente para o resultado
    *resultado = (*a) * (*b); // Realiza a multiplicação e armazena o resultado na memória alocada
    return resultado; // Retorna o ponteiro para o resultado
}

int main() {
    int x, y;
    cout << "Digite dois numeros inteiros: ";
    cin >> x >> y;

    int *ptrResultado = vezes(&x, &y); // Chama a função e recebe o ponteiro para o resultado

    cout << "O resultado da multiplicação e: " << *ptrResultado << endl;

    // Libera a memória alocada dinamicamente
    delete ptrResultado;

    return 0;
}