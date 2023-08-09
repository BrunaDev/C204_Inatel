#include <iostream>
#include <locale>

using namespace std;

// Função resposável pela verificação do número
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
	// Para não dar erro com acentos
	setlocale(LC_ALL, "Portuguese");
	
    int posicao;
    
    cout << "Digite a posição na Sequência de Fibonacci: ";
    cin >> posicao;
    
    if (posicao < 0) {
        cout << "Posição inválida. Deve ser um número não negativo.\n";
        return 1;
    }
    
    int resultado = fibonacci(posicao);
    cout << "O número na posição " << posicao << " na Sequência de Fibonacci é: " << resultado << endl;
    
    return 0;
}