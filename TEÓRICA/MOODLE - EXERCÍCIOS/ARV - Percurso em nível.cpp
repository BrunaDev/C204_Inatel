#include <iostream>
#include <queue>

using namespace std;

struct treenode {
    int info;
    treenode* esq;
    treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr& p, int x) {
    if (p == NULL) {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    } else if (x < p->info)
        tInsere(p->esq, x);
    else
        tInsere(p->dir, x);
}

void percursoEmNivel(treenodeptr arvore) {
    if (arvore == NULL)
        return;

    queue<treenodeptr> fila;
    fila.push(arvore);

    while (!fila.empty()) {
        treenodeptr noAtual = fila.front();
        fila.pop();

        cout << noAtual->info << " ";

        if (noAtual->esq != NULL)
            fila.push(noAtual->esq);

        if (noAtual->dir != NULL)
            fila.push(noAtual->dir);
    }
}

void liberaMemoria(treenodeptr arvore) {
    if (arvore != NULL) {
        liberaMemoria(arvore->esq);
        liberaMemoria(arvore->dir);
        delete arvore;
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

    cout << "Percurso em Nivel: ";
    percursoEmNivel(arvore);
    cout << endl;

    liberaMemoria(arvore);

    return 0;
}