#include <iostream>

using namespace std;

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
    int N;
    cout << "Digite o tamanho do vetor: ";
    cin >> N;

    int* vetor = new int[N];  // Aloca dinamicamente um vetor de inteiros com tamanho N

    int* ponteiro = vetor;  // Inicializa um ponteiro para apontar para o in�cio do vetor

    cout << "Digite os " << N << " elementos separados por espa�o: ";
    for (int i = 0; i < N; i++) {
        cin >> *ponteiro;  // L� um elemento e insere no vetor usando o ponteiro
        ponteiro++;  // Move o ponteiro para a pr�xima posi��o do vetor
    }

    // Reinicializa o ponteiro para apontar para o in�cio do vetor
    ponteiro = vetor;

    cout << "Elementos do vetor: ";
    for (int i = 0; i < N; i++) {
        cout << *ponteiro << " ";  // Mostra o elemento apontado pelo ponteiro
        ponteiro++;  // Move o ponteiro para o pr�ximo elemento
    }

    delete[] vetor;  // Libera a mem�ria alocada para o vetor

    return 0;
}