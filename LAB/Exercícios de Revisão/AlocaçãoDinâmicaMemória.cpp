#include <iostream>
#include <locale>

using namespace std;

int main() {
	// Para n�o dar erro com acentos
	setlocale(LC_ALL, "Portuguese");
	
    int n;
    
    cout << "Digite o n�mero de elementos: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "N�mero inv�lido. Deve ser um n�mero positivo.\n";
        return 1;
    }
    
    // Aloca��o din�mica do vetor
    int* vetor = new int[n];
    
    cout << "Digite os elementos:\n";
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }
    
    // C�lculo da m�dia aritm�tica simples
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += vetor[i];
    }
    double media = static_cast<double>(soma) / n;
    
    cout << "A m�dia aritm�tica simples dos valores �: " << media << endl;
    
    // Libera��o da mem�ria alocada
    delete[] vetor;
    
    return 0;
}