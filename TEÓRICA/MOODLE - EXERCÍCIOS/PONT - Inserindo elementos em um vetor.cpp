#include <iostream>

using namespace std;

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
    int N;
    cout << "Digite o tamanho do vetor: ";
    cin >> N;

    int* vetor = new int[N];  // Aloca dinamicamente um vetor de inteiros com tamanho N

    int* ponteiro = vetor;  // Inicializa um ponteiro para apontar para o início do vetor

    cout << "Digite os " << N << " elementos separados por espaço: ";
    for (int i = 0; i < N; i++) {
        cin >> *ponteiro;  // Lê um elemento e insere no vetor usando o ponteiro
        ponteiro++;  // Move o ponteiro para a próxima posição do vetor
    }

    // Reinicializa o ponteiro para apontar para o início do vetor
    ponteiro = vetor;

    cout << "Elementos do vetor: ";
    for (int i = 0; i < N; i++) {
        cout << *ponteiro << " ";  // Mostra o elemento apontado pelo ponteiro
        ponteiro++;  // Move o ponteiro para o próximo elemento
    }

    delete[] vetor;  // Libera a memória alocada para o vetor

    return 0;
}