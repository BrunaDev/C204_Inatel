#include <iostream>
#include <locale>

using namespace std;

// Fun��o respos�vel pela verifica��o do n�mero
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
	// Para n�o dar erro com acentos
	setlocale(LC_ALL, "Portuguese");
	
    int posicao;
    
    cout << "Digite a posi��o na Sequ�ncia de Fibonacci: ";
    cin >> posicao;
    
    if (posicao < 0) {
        cout << "Posi��o inv�lida. Deve ser um n�mero n�o negativo.\n";
        return 1;
    }
    
    int resultado = fibonacci(posicao);
    cout << "O n�mero na posi��o " << posicao << " na Sequ�ncia de Fibonacci �: " << resultado << endl;
    
    return 0;
}