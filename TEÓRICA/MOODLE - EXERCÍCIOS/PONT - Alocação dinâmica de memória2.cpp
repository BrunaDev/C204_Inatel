#include <iostream>
#include <iomanip>

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
    
    int N;
    cout << "Entre com o n�mero de alunos: ";
    cin >> N;

    // Aloca mem�ria para um vetor de estruturas para armazenar as notas dos alunos
    Notas* alunos = new Notas[N];

    for (int i = 0; i < N; i++) {
        cout << "Aluno [" << i + 1 << "]" << endl;
        cout << "Digite a nota 1: ";
        cin >> alunos[i].nota1;
        cout << "Digite a nota 2: ";
        cin >> alunos[i].nota2;
        cout << "Digite a nota 3: ";
        cin >> alunos[i].nota3;
        cout << "Digite a nota 4: ";
        cin >> alunos[i].nota4;

        // Calcula a m�dia do aluno atual
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3 + alunos[i].nota4) / 4.0;
    }

    double mediaAlunos = 0.0;
    
    for (int i = 0; i < N; i++) {
        mediaAlunos += alunos[i].media;
    }

    // Calcula a m�dia das m�dias dos alunos
    double mediaDaTurma = mediaAlunos / N;

    // Exibe a m�dia com duas casas decimais
    cout << fixed << setprecision(2);
    cout << "A m�dia das m�dias dos alunos �: " << mediaDaTurma << endl;

    // Libera a mem�ria alocada para o vetor de estruturas
    delete[] alunos;

    return 0;
}