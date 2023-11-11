#include <iostream>
#include <queue>
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

void preOrdem(treenodeptr raiz){
	if(raiz != NULL){
		cout << raiz->info << " ";
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void emOrdem(treenodeptr raiz){
	if(raiz != NULL){
		emOrdem(raiz->esq);
		cout << raiz->info << " ";
		emOrdem(raiz->dir);
	}
}

void posOrdem(treenodeptr raiz){
	if(raiz != NULL){
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		cout << raiz->info << " ";
	}
}

void emNivel(treenodeptr raiz){
	if(raiz != NULL){
		queue<treenodeptr> fila;
		fila.push(raiz);
		while(!fila.empty()){
			treenodeptr atual = fila.front();
			fila.pop();
			cout << atual->info << " ";
			if(atual->esq != NULL)
				fila.push(atual->esq);
			if(atual->dir != NULL)
				fila.push(atual->dir);
		}
	}
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
	treenodeptr arvore = NULL;
	int x, y, n, op;
	
	cout << "Entre com o numero de elementos na arvore:" << endl;
	cin >> n;
	cout << "Entre com os elementos da arvore:" << endl;
	for(int i = 0; i < n; i++){
		cin >> x;
		
		tInsere(arvore, x);
	}
	
	cout << "1 -> Pesquisar" << endl;
	cout << "2 -> Remover" << endl;
	cout << "3 -> Pre ordem" << endl;
	cout << "4 -> Em ordem" << endl;
	cout << "5 -> Pos ordem" << endl;
	cout << "6 -> Em nivel" << endl;
	cout << "0 -> Terminar programa" << endl;
	
	cout << "Entre com op:\n";
	cin >> op;
	
	while(op != 0){
		switch(op){
			case 1:
				cout << "Entre com o elemento que quer pesquisar:" << endl;
				cin >> x;
				if(tPesq(arvore, x) == NULL)
					cout << "Elemento nao encontrado" << endl;
				else
					cout << "Elemento encontrado" << endl;
				break;
			case 2:
				cout << "Entre com o elemento que deseja remover da arvore:" << endl;
				cin >> x;
				y = tRemove(arvore, x);
				if(y == 0)
					cout << "Elemento removido com sucesso" << endl;
				else
					cout << "Elemento nao encontrado para remocao" << endl;
				break;
			case 3:
				cout << "Pre ordem:" << endl;
				preOrdem(arvore);
				cout << endl;
				break;
			case 4:
				cout << "Em ordem:" << endl;
				emOrdem(arvore);
				cout << endl;
				break;
			case 5:
				cout << "Pos ordem:" << endl;
				posOrdem(arvore);
				cout << endl;
				break;
			case 6:
				cout << "Em nivel:" << endl;
				emNivel(arvore);
				cout << endl;
				break;
			default:
				cout << "Operacao invalida" << endl;
		}
		cout << "Entre com op:\n";
		cin >> op;
	}
	
	tDestruir(arvore);
	
	return 0;
}