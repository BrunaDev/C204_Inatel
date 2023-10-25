#include <iostream>
#include <iomanip> // Para formatar a saída com duas casas decimais

using namespace std;

struct Notas {
    int nota1;
    int nota2;
    int nota3;
    int nota4;
    double media;
};

int main() {
	
	setlocale(LC_ALL, "Portuguese");
	
    Notas* aluno = new Notas; // Aloca memória para a struct

    // Solicita as notas do usuário
    cout << "Digite a nota 1: ";
    cin >> aluno->nota1;

    cout << "Digite a nota 2: ";
    cin >> aluno->nota2;

    cout << "Digite a nota 3: ";
    cin >> aluno->nota3;

    cout << "Digite a nota 4: ";
    cin >> aluno->nota4;

    // Calcula a média
    aluno->media = (aluno->nota1 + aluno->nota2 + aluno->nota3 + aluno->nota4) / 4.0;

    // Exibe a média com duas casas decimais
    cout << fixed << setprecision(2);
    cout << "A média das notas é: " << aluno->media << endl;

    delete aluno; // Libera a memória alocada para a struct

    return 0;
}