#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct treenode {
    string info;
    treenode* esq;
    treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr& p, string nome) {
    if (p == NULL) {
        p = new treenode;
        p->info = nome;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (nome < p->info)
        tInsere(p->esq, nome);
    else
        tInsere(p->dir, nome);
}

treenodeptr tPesq(treenodeptr p, string nome) {
    if (p == NULL)
        return NULL;
    else if (nome == p->info)
        return p;
    else if (nome < p->info)
        return tPesq(p->esq, nome);
    else
        return tPesq(p->dir, nome);
}

void tListarEmOrdem(treenodeptr p) {
    if (p != NULL) {
        tListarEmOrdem(p->esq);
        cout << p->info << endl;
        tListarEmOrdem(p->dir);
    }
}

treenodeptr tMenor(treenodeptr& raiz) {
    treenodeptr t;
    t = raiz;
    if (t->esq == NULL) {
        raiz = raiz->dir;
        return t;
    }
    else
        return tMenor(raiz->esq);
}

int tRemove(treenodeptr& raiz, string nome) {
    treenodeptr p;
    if (raiz == NULL)
        return 1;
    if (nome == raiz->info) {
        p = raiz;
        if (raiz->esq == NULL)
            raiz = raiz->dir;
        else if (raiz->dir == NULL)
            raiz = raiz->esq;
        else {
            p = tMenor(raiz->dir);
            raiz->info = p->info;
        }
        delete p;
        return 0;
    }
    else if (nome < raiz->info)
        return tRemove(raiz->esq, nome);
    else
        return tRemove(raiz->dir, nome);
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
        getline(cin, nome);
        tInsere(arvore, nome);
    }

    int choice;
    string nome;
    do {
    	cout << "------------x------------" << endl;
        cout << "Escolha o que deseja fazer (1-Pesquisar; 2-Remover; 3-Mostrar; 0-Terminar): ";
        cin >> choice;
        cin.ignore(); // Consumir a nova linha após a escolha

        switch (choice) {
        case 1:
            cout << "Digite o nome a ser pesquisado: ";
            getline(cin, nome);
            if (tPesq(arvore, nome) == NULL)
                cout << "Pessoa não encontrada" << endl;
            else
                cout << "Pessoa encontrada" << endl;
            break;
        case 2:
            cout << "Digite o nome a ser removido: ";
            getline(cin, nome);
            if (tRemove(arvore, nome) == 0)
                cout << "Pessoa removida com sucesso" << endl;
            else
                cout << "Pessoa não encontrada" << endl;
            break;
        case 3:
            tListarEmOrdem(arvore);
            break;
        }
    } while (choice != 0);

    tDestruir(arvore);
    return 0;
}