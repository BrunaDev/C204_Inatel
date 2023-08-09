#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome; // Variável que armazena o nome
    int idade; // Variável que armazena a idade
};

int main() {
    const int MAX_PESSOAS = 100;
    Pessoa pessoas[MAX_PESSOAS];
    int n = 0; // Número de pessoas inseridas
    int idade; 
    
    cout << "Digite a idade e depois o nome das pessoas desejadas(para encerrar, digite a idade -1):\n";
    while (true) {
        cin >> idade;
        if (idade == -1) {
            break;
        }
        
        if (n >= MAX_PESSOAS) {
            cout << "Limite máximo de pessoas atingido.\n";
            break;
        }
        
        pessoas[n].idade = idade; 
        
        // o nome só é inserido após a verificação no numero inserido
        cin >> pessoas[n].nome;
        n++;
    }
    
    if (n == 0) {
        cout << "Nenhuma pessoa inserida.\n";
        return 0;
    }
    
    int indiceMaisNovo = 0;
    int indiceMaisVelho = 0;
    
    // Faz a verificação do mais novo e do mais velho
    for (int i = 1; i < n; i++) {
        if (pessoas[i].idade < pessoas[indiceMaisNovo].idade) {
            indiceMaisNovo = i;
        }
        if (pessoas[i].idade > pessoas[indiceMaisVelho].idade) {
            indiceMaisVelho = i;
        }
    }
    
    cout << "Pessoa mais nova: " << pessoas[indiceMaisNovo].nome << endl;
    cout << "Pessoa mais velha: " << pessoas[indiceMaisVelho].nome << endl;
    
    return 0;
}