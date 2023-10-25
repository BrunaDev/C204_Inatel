//Aloca��o din�mica

#include <iostream>

using namespace std;

struct posicao {
	int dado;
	posicao * proximo;
}

int main(){
	
	int entrada = 0;
	
	posicao * ponteiro = NULL;
	
	while(true){
		
		cin>> entrada;
		if(entrada != -1){
			if(ponteiro == NULL) {
				ponteiro = new posicao; //aloca mem�ria
				(*ponteiro).dado = entrada;
				(*ponteiro).proximo = NULL;
			}
			else {
				posicao * aux = ponteiro;
				while((*aux).proximo != NULL){ //a posi��o apontada n�o � nula
					aux = (*aux).proximo; // verifica o pr�ximo
				}
				posicao * temp = new posicao;
				(*aux).dado = entrada;
				(*aux).proximo = NULL;
				(*aux).proximo = temp;
				//Quando se tem uma struct, podemos usar esta setinha (->) ao inv�s do *
				//aux->proximo = temp;
			}
			
			//free(ponteiro); //desaloca mem�ria
		}
		else{ break; }
	}
	
	return 0;
}

// 1� regra da aloca��o din�mica: nunca podemos perder nossa refer�ncia!
// 2� regra da aloca��o din�mica: � nossa responsabilidade desalocar a mem�ria!