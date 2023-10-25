//Alocação dinâmica

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
				ponteiro = new posicao; //aloca memória
				(*ponteiro).dado = entrada;
				(*ponteiro).proximo = NULL;
			}
			else {
				posicao * aux = ponteiro;
				while((*aux).proximo != NULL){ //a posição apontada não é nula
					aux = (*aux).proximo; // verifica o próximo
				}
				posicao * temp = new posicao;
				(*aux).dado = entrada;
				(*aux).proximo = NULL;
				(*aux).proximo = temp;
				//Quando se tem uma struct, podemos usar esta setinha (->) ao invés do *
				//aux->proximo = temp;
			}
			
			//free(ponteiro); //desaloca memória
		}
		else{ break; }
	}
	
	return 0;
}

// 1ª regra da alocação dinâmica: nunca podemos perder nossa referência!
// 2ª regra da alocação dinâmica: é nossa responsabilidade desalocar a memória!