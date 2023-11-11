#include <iostream>
using namespace std;

struct treenode {
    string info;
    treenode* esq;
    treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr &p, string x) {
    if (p == NULL) {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info)
        tInsere(p->esq, x);
    else
        tInsere(p->dir, x);
}

treenodeptr tPesq(treenodeptr p, string x) { //Verifica na árvore se o nome existe
    if (p == NULL)
        return NULL;
    else if (x == p->info)
        return p;
    else if (x < p->info)
        return tPesq(p->esq, x);
    else
        return tPesq(p->dir, x);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    treenodeptr arvore = NULL;
    
    // Variáveis
    string x;
    int n;

    cout << "Entre com a quantidade de nomes: ";
    cin >> n;

	cout << "------x------" << endl;
	
	cout << "Insira os nomes: " << endl;
    for (int i = 0; i < n; i++) {
        cin.ignore(); // Limpa o buffer de entrada
        getline(cin, x);
        tInsere(arvore, x);
    }

	cout << "------x------" << endl;
	
    cout << "Entre com o nome a ser pesquisado: ";
    cin.ignore();
    getline(cin, x);

    if (tPesq(arvore, x) == NULL)
        cout << "Pessoa não encontrada" << endl;
    else
        cout << "Pessoa encontrada" << endl;

    return 0;
}