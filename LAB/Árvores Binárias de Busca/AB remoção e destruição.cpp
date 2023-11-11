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
		raiz = raiz->dir; // substitui o menor n� pelo seu filho direito (que pode ser nulo)
		return t; // retorna o menor n�
	}
	else // continua a busca na sub-�rvore esquerda
		return tMenor(raiz->esq);
}

int tRemove(treenodeptr &raiz, int x){
	treenodeptr p;
	if(raiz == NULL) // �rvore vazia
		return 1;
	if(x == raiz->info){
		p = raiz;
		if(raiz->esq == NULL) // a raiz n�o tem filho esquerdo
			raiz = raiz->dir;
		else if(raiz->dir == NULL) // a raiz n�o tem filho direito
			raiz = raiz->esq;
		else{ // a raiz tem ambos o s filhos
			p = tMenor(raiz->dir); // desliga o n� com menor elemento
			raiz->info = p->info; // armazena o valor na raiz da �rvore
		}
		delete p; // libera o n� removido
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