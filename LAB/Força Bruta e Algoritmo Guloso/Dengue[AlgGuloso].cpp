#include <iostream>
#include <climits>

using namespace std;

int main() {
    int custo[100][100]; // 100 -> número máximo de focos de dengue
                         // custo[i][j] = custo de ir do foco 'i' para o foco 'j'
    int cidade_inicial; // Primeira e última cidade (foco)
    int n; // número de focos de dengue

    cout << "Entre com o numero de focos de dengue" << endl;
    cin >> n;
    cout << "Entre com o foco de dengue que representa a casa de Joao" << endl;
    cin >> cidade_inicial;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Entre com o custo de ir do foco " << i << " para o foco " << j << endl;
            cin >> custo[i][j];
            custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
        }
    }

    bool vis[100]; // marca se já visitou ou não um foco
    int menor_custo; // menor custo da viagem
    int custo_at; // menor custo atual
    int foco_atual; // foco atual
    int proximo_foco; // próximo foco

    // Inicializando vetor vis (nenhum foco foi visitado no início)
    for (int i = 0; i < n; i++)
        vis[i] = false;

    // Algoritmo guloso
    menor_custo = 0;
    foco_atual = cidade_inicial;
    for (int i = 0; i < n - 1; i++) { // n-1 vezes = quantidade de caminhos (exceto a volta para o foco inicial)
        vis[foco_atual] = true; // Marca que já visitei o foco atual
        // Encontrar qual o próximo foco mais próximo
        custo_at = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && custo_at > custo[foco_atual][j]) {
                proximo_foco = j;
                custo_at = custo[foco_atual][j];
            }
        }
        menor_custo += custo_at;
        foco_atual = proximo_foco;
    }
    menor_custo += custo[foco_atual][cidade_inicial];
    cout << "fb: " << menor_custo << endl;
    cout << "gl: " << menor_custo << endl;

    return 0;
}
