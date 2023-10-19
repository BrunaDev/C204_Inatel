#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int custo[100][100]; // 100 -> número máximo de lugares
                         // custo[i][j] = custo de ir do lugar 'i' para o lugar 'j'
    int n; // número de lugares
    int casa; // lugar onde Carla mora

    cout << "Entre com o numero de lugares que Carla tem que passar:" << endl;
    cin >> n;

    // Lendo as distâncias entre os lugares
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Entre com a distancia entre o lugar " << i << " e o lugar " << j << endl;
            cin >> custo[i][j];
            custo[j][i] = custo[i][j];
        }
    }

    cout << "Entre com o lugar que indica a casa de Carla:" << endl;
    cin >> casa;

    int lugar[100]; // vetor com os lugares a serem permutados
    int p; // variável auxiliar
    int maior_rota = 0; // maior rota da viagem
    int rota_atual; // rota atual

    // Colocando os lugares que serão permutados no vetor (todos exceto a casa)
    p = 0;
    for (int i = 0; i < n; i++) {
        if (i != casa) {
            lugar[p] = i;
            p++;
        }
    }

    // Força bruta
    do {
        rota_atual = custo[casa][lugar[0]]; // custo da casa até o primeiro lugar

        for (int i = 0; i < n - 2; i++) // somar custo de lugar[0]->lugar[1]->lugar[2]...lugar[n-3]->lugar[n-2]
            rota_atual += custo[lugar[i]][lugar[i + 1]];

        rota_atual += custo[lugar[n - 2]][casa]; // custo último lugar até a casa

        maior_rota = max(maior_rota, rota_atual);
    } while (next_permutation(lugar, lugar + (n - 1))); // n-1 = número de lugares a serem permutados
    // obs.: para fazer todas as permutações, o vetor deve estar ordenado no começo

    cout << "fb: " << maior_rota << endl;
    cout << "gl: " << maior_rota << endl;

    return 0;
}