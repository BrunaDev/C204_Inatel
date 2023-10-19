#include <iostream>
using namespace std;

// Definição da estrutura para armazenar a matrícula e idade de uma pessoa
struct Pessoa {
    int matricula;
    int idade;
};

int main() {
    int n;
    cout << "Digite o numero de pessoas: ";
    cin >> n;

    // Aloca dinamicamente um vetor de struct Pessoa com tamanho n
    Pessoa* pessoas = new Pessoa[n];

    // Preenche o vetor com as matrículas e idades das pessoas
    for (int i = 0; i < n; i++) {
        cout << "Digite a matricula e a idade da pessoa " << i + 1 << ": ";
        cin >> pessoas[i].matricula >> pessoas[i].idade;
    }

    // Encontra a pessoa mais velha
    int indiceMaiorIdade = 0;
    for (int i = 1; i < n; i++) {
        if (pessoas[i].idade > pessoas[indiceMaiorIdade].idade) {
            indiceMaiorIdade = i;
        }
    }

    // Exibe a matrícula e idade da pessoa mais velha
    cout << "A pessoa mais velha tem a matricula " << pessoas[indiceMaiorIdade].matricula
         << " e idade " << pessoas[indiceMaiorIdade].idade << " anos." << endl;

    // Libera a memória alocada dinamicamente
    delete[] pessoas;

    return 0;
}