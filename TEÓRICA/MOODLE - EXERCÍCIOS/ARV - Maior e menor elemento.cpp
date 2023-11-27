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

// Função para encontrar o maior elemento na árvore
int maior(treenodeptr arvore) {
    while (arvore->dir != NULL) {
        arvore = arvore->dir;
    }
    return arvore->info;
}

// Função para encontrar o menor elemento na árvore
int menor(treenodeptr arvore) {
    while (arvore->esq != NULL) {
        arvore = arvore->esq;
    }
    return arvore->info;
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

    int menorElemento = menor(arvore);
    int maiorElemento = maior(arvore);

    // cout << "Menor elemento: " << menorElemento << endl;
    // cout << "Maior elemento: " << maiorElemento << endl;
    cout << menorElemento << " e " << maiorElemento << endl;

    return 0;
}