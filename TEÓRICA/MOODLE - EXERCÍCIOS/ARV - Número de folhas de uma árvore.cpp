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

// Função para contar folhas em uma árvore
int contaFolhas(treenodeptr arvore) {
    if (arvore == NULL) {
        return 0; // Nenhum nó, portanto, zero folhas
    } else if (arvore->esq == NULL && arvore->dir == NULL) {
        return 1; // Apenas um nó, que é uma folha
    } else {
        return contaFolhas(arvore->esq) + contaFolhas(arvore->dir);
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

    int folhas = contaFolhas(arvore);

    cout << "Numero de folhas: " << folhas << endl;

    return 0;
}