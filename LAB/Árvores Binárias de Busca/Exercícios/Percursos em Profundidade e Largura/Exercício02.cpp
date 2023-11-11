#include <iostream>
#include <queue>
using namespace std;

struct treenode {
    string nome;
    int matricula;
    treenode* esq;
    treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr& p, string nome, int matricula) {
    if (p == NULL) {
        p = new treenode;
        p->nome = nome;
        p->matricula = matricula;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (nome < p->nome)
        tInsere(p->esq, nome, matricula);
    else
        tInsere(p->dir, nome, matricula);
}

void tPreOrdem(treenodeptr p) {
    if (p != NULL) {
        cout << p->nome << " - " << p->matricula << endl;
        tPreOrdem(p->esq);
        tPreOrdem(p->dir);
    }
}

void tEmOrdem(treenodeptr p) {
    if (p != NULL) {
        tEmOrdem(p->esq);
        cout << p->nome << " - " << p->matricula << endl;
        tEmOrdem(p->dir);
    }
}

void tPosOrdem(treenodeptr p) {
    if (p != NULL) {
        tPosOrdem(p->esq);
        tPosOrdem(p->dir);
        cout << p->nome << " - " << p->matricula << endl;
    }
}

void tEmNivel(treenodeptr p) {
    if (p == NULL)
        return;

    queue<treenodeptr> fila;
    fila.push(p);

    while (!fila.empty()) {
        treenodeptr atual = fila.front();
        fila.pop();
        cout << atual->nome << " - " << atual->matricula << endl;

        if (atual->esq != NULL)
            fila.push(atual->esq);

        if (atual->dir != NULL)
            fila.push(atual->dir);
    }
}

void tDestruir(treenodeptr& raiz) {
    if (raiz != NULL) {
        tDestruir(raiz->esq);
        tDestruir(raiz->dir);
        delete raiz;
    }
    raiz = NULL;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
    treenodeptr arvore = NULL;
    int n;
    cin >> n;
    cin.ignore(); // Consumir a nova linha após o número de pessoas

    for (int i = 0; i < n; i++) {
        string nome;
        int matricula;
        getline(cin, nome);
        cin >> matricula;
        cin.ignore(); // Consumir a nova linha após a matrícula
        tInsere(arvore, nome, matricula);
    }

	cout << "------------x------------" << endl;
    cout << "Pre-ordem:" << endl;
    tPreOrdem(arvore);
    cout << endl;

	cout << "------------x------------" << endl;
    cout << "Em ordem:" << endl;
    tEmOrdem(arvore);
    cout << endl;

	cout << "------------x------------" << endl;
    cout << "Pos-ordem:" << endl;
    tPosOrdem(arvore);
    cout << endl;

	cout << "------------x------------" << endl;
    cout << "Em nível:" << endl;
    tEmNivel(arvore);

    tDestruir(arvore);
    return 0;
}