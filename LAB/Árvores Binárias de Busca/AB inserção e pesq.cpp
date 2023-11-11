#include <iostream>
using namespace std;

struct treenode{
	int info;
	treenode* esq;
	treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr &p, int x){
	if(p == NULL){ // insere x na raiz
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else if(x < p->info) // insere x na sub-árvore esquerda
		tInsere(p->esq, x);
	else                 // insere x na sub-árvore direita
		tInsere(p->dir, x);
}

treenodeptr tPesq(treenodeptr p, int x){
	if(p == NULL) // elemento não encontrado
		return NULL;
	else if(x == p->info) // elemento encontrado na raiz
		return p;
	else if(x < p->info) // pesquisa na sub-árvore esquerda
		return tPesq(p->esq, x);
	else                 // pesquisa na sub-árvore direita
		return tPesq(p->dir, x);
}

int main(){
	treenodeptr arvore = NULL;
	int x, n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> x;
		
		tInsere(arvore, x);
	}
	
	cin >> x;
	
	if(tPesq(arvore, x) == NULL)
		cout << "Elemento nao encontrado" << endl;
	else
		cout << "Elemento encontrado" << endl;
	
	return 0;
}