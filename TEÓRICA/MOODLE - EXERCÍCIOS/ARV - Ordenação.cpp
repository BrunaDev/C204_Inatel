#include <iostream>

using namespace std;

struct treenode {
    int info;
    treenode* esq;
    treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr& p, int x) {
    if (p == NULL) { // insere x na raiz
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    } else if (x < p->info) // insere x na sub-árvore esquerda
        tInsere(p->esq, x);
    else                 // insere x na sub-árvore direita
        tInsere(p->dir, x);
}

// Função para percorrer a árvore em ordem decrescente
void percorreDecrescente(treenodeptr arvore) {
    if (arvore != NULL) {
        percorreDecrescente(arvore->dir);
        cout << arvore->info << " ";
        percorreDecrescente(arvore->esq);
    }
}

int main() {
    treenodeptr arvore = NULL;

    int x;

    do {
        cin >> x;

        if (x != -1) {
            tInsere(arvore, x);
        }

    } while (x != -1);

    cout << "Sequencia em ordem decrescente: ";
    percorreDecrescente(arvore);
    cout << endl;

    return 0;
}