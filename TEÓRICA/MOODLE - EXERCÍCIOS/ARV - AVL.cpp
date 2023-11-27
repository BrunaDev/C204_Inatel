#include <iostream>
#include <queue>

using namespace std;

struct treenode {
    int info;
    treenode* esq;
    treenode* dir;
};

typedef treenode* treenodeptr;

struct avlnode {
    int info;
    avlnode* esq;
    avlnode* dir;
    int altura;
};

typedef avlnode* avlnodeptr;

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

int tPesq(treenodeptr p, int x, int& chamadas) {
    if (p == NULL) {
        return -1;
    } else {
        chamadas++;
        if (x == p->info)
            return chamadas;
        else if (x < p->info)
            return tPesq(p->esq, x, chamadas);
        else
            return tPesq(p->dir, x, chamadas);
    }
}

int altura(avlnodeptr p) {
    if (p == NULL)
        return 0;
    return p->altura;
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int atualizaAltura(avlnodeptr p) {
    if (p == NULL)
        return 0;
    return 1 + maximo(altura(p->esq), altura(p->dir));
}

int fatorBalanceamento(avlnodeptr p) {
    if (p == NULL)
        return 0;
    return altura(p->esq) - altura(p->dir);
}

avlnodeptr rotacaoDireita(avlnodeptr y) {
    avlnodeptr x = y->esq;
    avlnodeptr T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = atualizaAltura(y);
    x->altura = atualizaAltura(x);

    return x;
}

avlnodeptr rotacaoEsquerda(avlnodeptr x) {
    avlnodeptr y = x->dir;
    avlnodeptr T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = atualizaAltura(x);
    y->altura = atualizaAltura(y);

    return y;
}

avlnodeptr tInsereAVL(avlnodeptr p, int x) {
    if (p == NULL) {
        avlnodeptr novoNo = new avlnode;
        novoNo->info = x;
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        novoNo->altura = 1;
        return novoNo;
    }

    if (x < p->info)
        p->esq = tInsereAVL(p->esq, x);
    else if (x > p->info)
        p->dir = tInsereAVL(p->dir, x);
    else
        return p; // Não permite elementos duplicados

    p->altura = atualizaAltura(p);

    int balanceamento = fatorBalanceamento(p);

    // Casos de rotação
    if (balanceamento > 1) {
        if (x < p->esq->info)
            return rotacaoDireita(p);
        else {
            p->esq = rotacaoEsquerda(p->esq);
            return rotacaoDireita(p);
        }
    }

    if (balanceamento < -1) {
        if (x > p->dir->info)
            return rotacaoEsquerda(p);
        else {
            p->dir = rotacaoDireita(p->dir);
            return rotacaoEsquerda(p);
        }
    }

    return p;
}

int tPesqAVL(avlnodeptr p, int x, int& chamadas) {
    if (p == NULL) {
        return -1;
    } else {
        chamadas++;
        if (x == p->info)
            return chamadas;
        else if (x < p->info)
            return tPesqAVL(p->esq, x, chamadas);
        else
            return tPesqAVL(p->dir, x, chamadas);
    }
}

void liberaMemoria(treenodeptr p) {
    if (p != NULL) {
        liberaMemoria(p->esq);
        liberaMemoria(p->dir);
        delete p;
    }
}

void liberaMemoriaAVL(avlnodeptr p) {
    if (p != NULL) {
        liberaMemoriaAVL(p->esq);
        liberaMemoriaAVL(p->dir);
        delete p;
    }
}

int main() {
    treenodeptr arvore = NULL;
    avlnodeptr arvoreAVL = NULL;

    int x;
    int valorPesquisa;

    // Construindo árvore binária comum
    // Construindo árvore AVL
    
    arvoreAVL = NULL;
    do {
        cin >> x;

        if (x != 0) {
            tInsere(arvore, x);
            arvoreAVL = tInsereAVL(arvoreAVL, x);
        }

    } while (x != 0);

    cin >> valorPesquisa;

    int chamadasPesquisaNormal = 0;
    int chamadasPesquisaAVL = 0;
    
    tPesq(arvore, valorPesquisa, chamadasPesquisaNormal);
    cout << "Arvore normal: " << chamadasPesquisaNormal << endl;

    tPesqAVL(arvoreAVL, valorPesquisa, chamadasPesquisaAVL);
    cout << "AVL: " << chamadasPesquisaAVL << endl;

	liberaMemoria(arvore);
    liberaMemoriaAVL(arvoreAVL);

    return 0;
}