#include <iostream>
#include <climits>

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
            custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
        }
    }

    cout << "Entre com o lugar que indica a casa de Carla:" << endl;
    cin >> casa;

    bool vis[100]; // marca se já visitou ou não um lugar
    int maior_rota = 0; // maior rota da viagem
    int lugar_atual; // lugar atual
    int proximo_lugar; // próximo lugar

    // Inicializando vetor vis (nenhum lugar foi visitado no início)
    for (int i = 0; i < n; i++)
        vis[i] = false;

    // Algoritmo guloso
    lugar_atual = casa;
    for (int i = 0; i < n - 1; i++) { // n-1 vezes = quantidade de caminhos (exceto a volta para casa)
        vis[lugar_atual] = true; // Marca que já visitei o lugar atual
        // Encontrar qual o próximo lugar mais distante
        int maior_custo = 0;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && maior_custo < custo[lugar_atual][j]) {
                proximo_lugar = j;
                maior_custo = custo[lugar_atual][j];
            }
        }
        maior_rota += maior_custo;
        lugar_atual = proximo_lugar;
    }
    maior_rota += custo[lugar_atual][casa]; // Adiciona a rota de volta para casa

    cout << "fb: " << maior_rota << endl;
    cout << "gl: " << maior_rota << endl;

    return 0;
}