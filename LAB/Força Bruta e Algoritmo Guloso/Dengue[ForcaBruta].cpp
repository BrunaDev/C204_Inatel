#include <iostream>
#include <climits>
#include <algorithm>


using namespace std;

int main() {
    int custo[100][100];  // 100 -> número máximo de cidades
    int n;  // número de cidades
    int cidade_inicial;

    cout << "Entre com o número de focos de dengue:\n";
    cin >> n;

    // Lendo as distâncias entre os focos de dengue
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Entre com a distancia entre o foco " << i << " e o foco " << j << endl;
            cin >> custo[i][j];
            custo[j][i] = custo[i][j];
        }
    }

    cout << "Entre com o foco de dengue que representa a casa de Joao:\n";
    cin >> cidade_inicial;

    int cidade[100];  // vetor com os focos de dengue a serem permutados
    int p;  // variável auxiliar
    int menor_custo;  // menor custo da viagem
    int custo_caminho;  // custo do caminho

    // Colocando os focos de dengue que serão permutados no vetor (todos exceto o inicial)
    p = 0;
    for (int i = 0; i < n; i++) {
        if (i != cidade_inicial) {
            cidade[p] = i;
            p++;
        }
    }

    // Força bruta
    menor_custo = INT_MAX;  // inicializo o custo com infinito
    do {
        custo_caminho = custo[cidade_inicial][cidade[0]];  // custo da cidade inicial -> cidade[0]

        for (int i = 0; i < n - 2; i++)  // somar custo de cidade[0]->cidade[1]->cidade[2]...cidade[n-3]->cidade[n-2]
            custo_caminho += custo[cidade[i]][cidade[i + 1]];

        custo_caminho += custo[cidade[n - 2]][cidade_inicial];  // custo cidade[n-2] -> cidade inicial

        menor_custo = min(menor_custo, custo_caminho);
    } while (next_permutation(cidade, cidade + (n - 1)));  // n-1 = número de cidades a serem permutadas
    // obs.: para fazer todas as permutações, o vetor deve estar ordenado no começo

    cout << "fb: " << menor_custo << endl;
    cout << "gl: " << menor_custo << endl;
    return 0;
}