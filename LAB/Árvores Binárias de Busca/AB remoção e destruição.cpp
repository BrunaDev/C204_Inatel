#include <iostream>
using namespace std;

struct treenode{
	int info;
	treenode* esq;
	treenode* dir;
};

typedef treenode* treenodeptr;

treenodeptr tMenor(treenodeptr &raiz){
	treenodeptr t;
	t = raiz;
	if(t->esq == NULL){ // encontrou o menor valor
		raiz = raiz->dir; // substitui o menor nó pelo seu filho direito (que pode ser nulo)
		return t; // retorna o menor nó
	}
	else // continua a busca na sub-árvore esquerda
		return tMenor(raiz->esq);
}

int tRemove(treenodeptr &raiz, int x){
	treenodeptr p;
	if(raiz == NULL) // árvore vazia
		return 1;
	if(x == raiz->info){
		p = raiz;
		if(raiz->esq == NULL) // a raiz não tem filho esquerdo
			raiz = raiz->dir;
		else if(raiz->dir == NULL) // a raiz não tem filho direito
			raiz = raiz->esq;
		else{ // a raiz tem ambos o s filhos
			p = tMenor(raiz->dir); // desliga o nó com menor elemento
			raiz->info = p->info; // armazena o valor na raiz da árvore
		}
		delete p; // libera o nó removido
		return 0;
	}
	else if(x < raiz->info)
		return tRemove(raiz->esq, x);
	else
		return tRemove(raiz->dir, x);
}

void tDestruir(treenodeptr &raiz){
	if(raiz != NULL){
		tDestruir(raiz->esq);
		tDestruir(raiz->dir);
		delete raiz;
	}
	raiz = NULL;
}

int main(){
	
	return 0;
}