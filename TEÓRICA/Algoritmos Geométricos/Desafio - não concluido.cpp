#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> // Adicionando esta linha para incluir a biblioteca cmath

using namespace std;

struct ponto {
    int x;
    int y;
};

// Declara��o antecipada das fun��es
double distancia(ponto a, ponto b);
int lado(ponto a, ponto b, ponto p);
vector<ponto> fecho_convexo(vector<ponto>& pontos);

// Vari�vel global
ponto ponto_inferior;

// Fun��o para verificar o lado de um ponto em rela��o a uma linha
int lado(ponto a, ponto b, ponto p) {
    int area = (a.x * (b.y - p.y) + b.x * (p.y - a.y) + p.x * (a.y - b.y));
    if (area > 0) {
        return 1; // � esquerda
    } else if (area < 0) {
        return -1; // � direita
    } else {
        return 0; // alinhado
    }
}

// Fun��o para comparar dois pontos para ordena��o no algoritmo de Graham
bool comparar_pontos(ponto a, ponto b) {
    // Verifica o lado em rela��o ao ponto mais baixo
    int lado_resultado = lado(ponto_inferior, a, b);
    if (lado_resultado == 0) {
        // Se est�o alinhados, escolhe o mais pr�ximo
        return (distancia(ponto_inferior, a) < distancia(ponto_inferior, b));
    }
    return (lado_resultado == -1);
}

// Fun��o para calcular a dist�ncia entre dois pontos
double distancia(ponto a, ponto b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// Fun��o para calcular o fecho convexo usando o algoritmo de Graham
vector<ponto> fecho_convexo(vector<ponto>& pontos) {
    // Encontrar o ponto mais baixo (com a menor coordenada y)
    ponto_inferior = *min_element(pontos.begin(), pontos.end(), [](ponto a, ponto b) {
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });

    // Ordenar os pontos com base no �ngulo polar em rela��o ao ponto mais baixo
    sort(pontos.begin(), pontos.end(), comparar_pontos);

    // Inicializar pilha para armazenar pontos do fecho convexo
    vector<ponto> pilha;
    pilha.push_back(pontos[0]);
    pilha.push_back(pontos[1]);

    // Construir o fecho convexo
    for (size_t i = 2; i < pontos.size(); i++) {
        while (pilha.size() > 1 && lado(pilha[pilha.size() - 2], pilha[pilha.size() - 1], pontos[i]) != -1) {
            pilha.pop_back();
        }
        pilha.push_back(pontos[i]);
    }

    return pilha;
}

int main() {
    int num_terrenos;
    cout << "Digite o n�mero de reservas florestais: ";
    cin >> num_terrenos;

    for (int i = 0; i < num_terrenos; i++) {
        int num_arvores;
        cout << "Para a reserva florestal " << i + 1 << ":" << endl;
        cout << "Digite o n�mero de �rvores: ";
        cin >> num_arvores;

        vector<ponto> arvores;
        cout << "Digite as coordenadas de cada �rvore (x y):" << endl;
        for (int j = 0; j < num_arvores; j++) {
            ponto arvore;
            cin >> arvore.x >> arvore.y;
            arvores.push_back(arvore);
        }

        // Calcular o fecho convexo das coordenadas das �rvores
        vector<ponto> fecho = fecho_convexo(arvores);

        // Calcular a quantidade m�nima de material para cercar o fecho convexo
        double material = 0.0;
        for (size_t j = 0; j < fecho.size() - 1; j++) {
            material += distancia(fecho[j], fecho[j + 1]);
        }
        material += distancia(fecho[fecho.size() - 1], fecho[0]);

        cout << "Quantidade m�nima de material para cercar a reserva: " << material << endl;
    }

    return 0;
}