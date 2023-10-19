#include <iostream>
#include <locale>

using namespace std;

int main() {
	// Para não dar erro com acentos
	setlocale(LC_ALL, "Portuguese");
	
    int n;
    
    cout << "Digite o número de elementos: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Número inválido. Deve ser um número positivo.\n";
        return 1;
    }
    
    // Alocação dinâmica do vetor
    int* vetor = new int[n];
    
    cout << "Digite os elementos:\n";
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }
    
    // Cálculo da média aritmética simples
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += vetor[i];
    }
    double media = static_cast<double>(soma) / n;
    
    cout << "A média aritmética simples dos valores é: " << media << endl;
    
    // Liberação da memória alocada
    delete[] vetor;
    
    return 0;
}