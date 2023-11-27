#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath> // Adicionando esta linha para incluir a biblioteca cmath

using namespace std;

struct ponto {
    int x;
    int y;
};

// Declaração antecipada das funções
double distancia(ponto a, ponto b);
int lado(ponto a, ponto b, ponto p);
vector<ponto> fecho_convexo(vector<ponto>& pontos);

// Variável global
ponto ponto_inferior;

// Função para verificar o lado de um ponto em relação a uma linha
int lado(ponto a, ponto b, ponto p) {
    int area = (a.x * (b.y - p.y) + b.x * (p.y - a.y) + p.x * (a.y - b.y));
    if (area > 0) {
        return 1; // à esquerda
    } else if (area < 0) {
        return -1; // à direita
    } else {
        return 0; // alinhado
    }
}

// Função para comparar dois pontos para ordenação no algoritmo de Graham
bool comparar_pontos(ponto a, ponto b) {
    // Verifica o lado em relação ao ponto mais baixo
    int lado_resultado = lado(ponto_inferior, a, b);
    if (lado_resultado == 0) {
        // Se estão alinhados, escolhe o mais próximo
        return (distancia(ponto_inferior, a) < distancia(ponto_inferior, b));
    }
    return (lado_resultado == -1);
}

// Função para calcular a distância entre dois pontos
double distancia(ponto a, ponto b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// Função para calcular o fecho convexo usando o algoritmo de Graham
vector<ponto> fecho_convexo(vector<ponto>& pontos) {
    // Encontrar o ponto mais baixo (com a menor coordenada y)
    ponto_inferior = *min_element(pontos.begin(), pontos.end(), [](ponto a, ponto b) {
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });

    // Ordenar os pontos com base no ângulo polar em relação ao ponto mais baixo
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
    cout << "Digite o número de reservas florestais: ";
    cin >> num_terrenos;

    for (int i = 0; i < num_terrenos; i++) {
        int num_arvores;
        cout << "Para a reserva florestal " << i + 1 << ":" << endl;
        cout << "Digite o número de árvores: ";
        cin >> num_arvores;

        vector<ponto> arvores;
        cout << "Digite as coordenadas de cada árvore (x y):" << endl;
        for (int j = 0; j < num_arvores; j++) {
            ponto arvore;
            cin >> arvore.x >> arvore.y;
            arvores.push_back(arvore);
        }

        // Calcular o fecho convexo das coordenadas das árvores
        vector<ponto> fecho = fecho_convexo(arvores);

        // Calcular a quantidade mínima de material para cercar o fecho convexo
        double material = 0.0;
        for (size_t j = 0; j < fecho.size() - 1; j++) {
            material += distancia(fecho[j], fecho[j + 1]);
        }
        material += distancia(fecho[fecho.size() - 1], fecho[0]);

        cout << "Quantidade mínima de material para cercar a reserva: " << material << endl;
    }

    return 0;
}