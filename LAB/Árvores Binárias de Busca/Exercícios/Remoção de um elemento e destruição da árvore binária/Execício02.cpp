#include <iostream>
using namespace std;

struct Pessoa {
    string nome;
    int matricula;
};

struct treenode {
    Pessoa info;
    treenode* esq;
    treenode* dir;
};

typedef treenode* treenodeptr;

void tInsere(treenodeptr& p, Pessoa pessoa) {
    if (p == NULL) {
        p = new treenode;
        p->info = pessoa;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (pessoa.matricula < p->info.matricula)
        tInsere(p->esq, pessoa);
    else
        tInsere(p->dir, pessoa);
}

treenodeptr tPesqNome(treenodeptr p, string nome) {
    if (p == NULL)
        return NULL;
    else if (nome == p->info.nome)
        return p;
    else if (nome < p->info.nome)
        return tPesqNome(p->esq, nome);
    else
        return tPesqNome(p->dir, nome);
}

treenodeptr tPesqMatricula(treenodeptr p, int matricula) {
    if (p == NULL)
        return NULL;
    else if (matricula == p->info.matricula)
        return p;
    else if (matricula < p->info.matricula)
        return tPesqMatricula(p->esq, matricula);
    else
        return tPesqMatricula(p->dir, matricula);
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

int tRemove(treenodeptr& raiz, string nome, int matricula) {
    treenodeptr p;
    if (raiz == NULL)
        return 1;
    if (nome == raiz->info.nome && matricula == raiz->info.matricula) {
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
    else if (nome < raiz->info.nome || (nome == raiz->info.nome && matricula < raiz->info.matricula))
        return tRemove(raiz->esq, nome, matricula);
    else
        return tRemove(raiz->dir, nome, matricula);
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
        Pessoa pessoa;
        getline(cin, pessoa.nome);
        cin >> pessoa.matricula;
        cin.ignore(); // Consumir a nova linha após a matrícula
        tInsere(arvore, pessoa);
    }

    int choice;
    string nome;
    int matricula;
    do {
    	cout << "------------x------------" << endl;
        cout << "Escolha o que deseja fazer (1-Pesquisar por nome e matrícula; 2-Remover; 0-Terminar): ";
        cin >> choice;
        cin.ignore(); // Consumir a nova linha após a escolha

        switch (choice) {
        case 1:
            cout << "Digite o nome a ser pesquisado: ";
            getline(cin, nome);
            cout << "Digite a matrícula a ser pesquisada: ";
            cin >> matricula;
            cin.ignore(); // Consumir a nova linha após a matrícula
            if (tPesqNome(arvore, nome) != NULL){
            	if (tPesqMatricula(arvore, matricula) != NULL)
                	cout << "Pessoa encontrada" << endl;
			}else{
                cout << "Pessoa não encontrada" << endl;}
            break;
        case 2:
            cout << "Digite o nome a ser removido: ";
            getline(cin, nome);
            cout << "Digite a matrícula a ser removida: ";
            cin >> matricula;
            cin.ignore(); // Consumir a nova linha após a matrícula
            if (tRemove(arvore, nome, matricula) == 0)
                cout << "Pessoa removida com sucesso" << endl;
            else
                cout << "Pessoa não encontrada para remoção" << endl;
            break;            
        }
    } while (choice != 0);

    tDestruir(arvore);
    return 0;
}