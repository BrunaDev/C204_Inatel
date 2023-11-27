#include <iostream>

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

bool ehPrimo(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int contaPrimosAux(treenodeptr arvore) {
    if (arvore == NULL)
        return 0;

    int cont = 0;
    if (ehPrimo(arvore->info))
        cont++;

    cont += contaPrimosAux(arvore->esq);
    cont += contaPrimosAux(arvore->dir);

    return cont;
}

int contaPrimos(treenodeptr arvore) {
    return contaPrimosAux(arvore);
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

    int primos = contaPrimos(arvore);

    cout << primos << " numeros primos" << endl;

    return 0;
}