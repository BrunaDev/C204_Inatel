#include <iostream>
using namespace std;

struct treenode {
    string info;
    int matricula;
    treenode* esq;
    treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr &p, string nome, int matricula) {
    if (p == NULL) {
        p = new treenode;
        p->info = nome;
        p->matricula = matricula;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (matricula < p->matricula)
        tInsere(p->esq, nome, matricula);
    else
        tInsere(p->dir, nome, matricula);
}

treenodeptr tPesq(treenodeptr p, string nome, int matricula) {
    if (p == NULL)
        return NULL;
    if (nome == p->info && matricula == p->matricula)
        return p;
    else if (matricula < p->matricula)
        return tPesq(p->esq, nome, matricula);
    else
        return tPesq(p->dir, nome, matricula);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    treenodeptr arvore = NULL;
    string nome;
    int matricula;
    int n;

    cout << "Entre com a quantidade de nomes: ";
    cin >> n;

	cout << "------x------" << endl;
	
    cout << "Insira os nomes e matrículas: " << endl;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        getline(cin, nome);
        cin >> matricula;
        tInsere(arvore, nome, matricula);
    }

	cout << "------x------" << endl;
	
    cout << "Entre com o nome a ser pesquisado: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Entre com a matrícula a ser pesquisada: ";
    cin >> matricula;

    if (tPesq(arvore, nome, matricula) == NULL)
        cout << "Pessoa não encontrada" << endl;
    else
        cout << "Pessoa encontrada" << endl;

    return 0;
}