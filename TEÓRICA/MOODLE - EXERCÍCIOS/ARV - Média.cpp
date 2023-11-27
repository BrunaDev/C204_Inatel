#include <iostream>
#include <iomanip> // Para usar setprecision

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
    else if(x < p->info) // insere x na sub-�rvore esquerda
        tInsere(p->esq, x);
    else                 // insere x na sub-�rvore direita
        tInsere(p->dir, x);
}

// Fun��o corrigida para calcular a soma dos elementos da �rvore
float somaArvore(treenodeptr arvore) {
    if (arvore == NULL) {
        return 0;
    } else {
        return arvore->info + somaArvore(arvore->esq) + somaArvore(arvore->dir);
    }
}

// Fun��o corrigida para calcular a m�dia dos elementos da �rvore
float media(treenodeptr arvore, int cont) {
    float soma = somaArvore(arvore);
    if (cont == 0) {
        return 0; // Evita divis�o por zero se a �rvore estiver vazia
    }
    return soma / cont;
}

int main() {
    treenodeptr arvore = NULL;

    int x;
    int cont = 0; // conta quantos n�meros foram inseridos

    do {
        cin >> x;

        if (x != -1) { // Certifique-se de n�o inserir o marcador -1 na �rvore
            tInsere(arvore, x);
            cont++;
        }

    } while (x != -1);

    cout << fixed << setprecision(2) << "Media: " << media(arvore, cont) << endl;

    return 0;
}