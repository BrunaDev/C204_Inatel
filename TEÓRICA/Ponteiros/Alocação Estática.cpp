//Alocação estática

#include <iostream>

using namespace std;

int main(){
	
	int a = 15;
	
	int b[5] = {133,221,65};
	
	int * p = &a; // ponteiro que recebe o endereço de a
	
	cout << *p << endl; // acessa o conteudo de a
	cout << p << endl; // acessa o endereço de a
	cout << b << endl; // acessa o primeiro endereço do vetor
	
	cout << b + 1 << endl; // acessa o segundo endereço do vetor
	cout << &b[1] << endl; // acessa o segundo endereço do vetor
	
	cout << b[1] << endl; // acessa o conteudo de b na posição 1
	cout << *(b+1) << endl; // acessa o conteudo de b na posição 1
	
	
	int * p = b; // ponteiro que recebe o endereço do vetor b
	
	cout << p + 1 << endl; // acessa o segundo endereço do vetor
	cout << &p[1] << endl; // acessa o segundo endereço do vetor
	
	cout << p[1] << endl; // acessa o conteudo de b na posição 1
	cout << *(p+1) << endl; // acessa o conteudo de b na posição 1
	
	return 0;
}