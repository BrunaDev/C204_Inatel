//Aloca��o est�tica

#include <iostream>

using namespace std;

int main(){
	
	int a = 15;
	
	int b[5] = {133,221,65};
	
	int * p = &a; // ponteiro que recebe o endere�o de a
	
	cout << *p << endl; // acessa o conteudo de a
	cout << p << endl; // acessa o endere�o de a
	cout << b << endl; // acessa o primeiro endere�o do vetor
	
	cout << b + 1 << endl; // acessa o segundo endere�o do vetor
	cout << &b[1] << endl; // acessa o segundo endere�o do vetor
	
	cout << b[1] << endl; // acessa o conteudo de b na posi��o 1
	cout << *(b+1) << endl; // acessa o conteudo de b na posi��o 1
	
	
	int * p = b; // ponteiro que recebe o endere�o do vetor b
	
	cout << p + 1 << endl; // acessa o segundo endere�o do vetor
	cout << &p[1] << endl; // acessa o segundo endere�o do vetor
	
	cout << p[1] << endl; // acessa o conteudo de b na posi��o 1
	cout << *(p+1) << endl; // acessa o conteudo de b na posi��o 1
	
	return 0;
}