#include <iostream>

using namespace std;

struct item
{
    int val;    // preço da pedra preciosa
    double vol; // volume em metros cúbicos
    int peso;   // peso em quilogramas
};

int main()
{
    int pd[100][100];     // valor máximo sendo:
                          // olhando do item 'i'->final
                          // olhando um carrinho de capacidade 'j'

    int caminho[100][100]; // utilizado para recuperar quais pedras foram escolhidas
                           // 0 -> não levar a pedra
                           // 1 -> levar a pedra

    int n = 5; // quantidade de pedras preciosas
    double capacidade_vol = 1.0; // capacidade total do carrinho em metros cúbicos (1 metro cúbico)
    int capacidade_peso = 400;   // capacidade total do carrinho em quilogramas
    item pedras[100]; // array de pedras preciosas

    // ENTRADA:
    // cout << "Entre com a quantidade de pedras preciosas:" << endl;
    // cin >> n;

    // cout << "Entre com a capacidade de volume do carrinho (em metros cúbicos):" << endl;
    // cin >> capacidade_vol;

    // cout << "Entre com a capacidade de peso do carrinho (em quilogramas):" << endl;
    // cin >> capacidade_peso;

    cout << "Entre com o preco, volume e peso de cada pedra preciosa:" << endl;
    cout << "Exemplo de entrada: 300 0.58 120" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Pedra " << i + 1 << ":" << endl;
        cin >> pedras[i].val;
		cin >> pedras[i].vol;
		cin >> pedras[i].peso;
    }

    // CASO BASE: Inicializar a primeira linha da matriz com zeros.
    for (int j = 0; j <= capacidade_peso; j++)
    {
        pd[0][j] = 0;
        caminho[0][j] = 0;
    }

    // CASO GERAL: Preencher a matriz de programação dinâmica.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= capacidade_peso; j++)
        {
            if (pedras[i - 1].peso > j || pedras[i - 1].vol > capacidade_vol)
            {
                // Se o peso da pedra atual for maior do que a capacidade de peso
                // ou o volume da pedra for maior do que a capacidade de volume,
                // não é possível incluir a pedra, então o valor máximo será o mesmo que antes.
                pd[i][j] = pd[i - 1][j];
                caminho[i][j] = 0;
            }
            else
            {
                // Caso contrário, temos duas opções: levar a pedra ou não levar.
                int escolha1 = pd[i - 1][j]; // Não levar a pedra.
                int escolha2 = pd[i - 1][j - pedras[i - 1].peso] + pedras[i - 1].val; // Levar a pedra.

                if (escolha1 >= escolha2)
                {
                    pd[i][j] = escolha1;
                    caminho[i][j] = 0;
                }
                else
                {
                    pd[i][j] = escolha2;
                    caminho[i][j] = 1;
                }
            }
        }
    }

    // Valor máximo que você pode obter levando as pedras preciosas:
    cout << "O valor maximo que você pode obter e: R$" << pd[n][capacidade_peso] << endl;

    // RECUPERAÇÃO
    // Começa na posição final
    int i = n;
    int j = capacidade_peso;
    cout << "Pedras que voce levaria:" << endl;

    while (i > 0 && j > 0)
    {
        if (caminho[i][j] == 1)
        {
            cout << "Pedra " << i << " - Preco: R$" << pedras[i - 1].val << ", Volume: " << pedras[i - 1].vol << " metros cubicos, Peso: " << pedras[i - 1].peso << " kg" << endl;
            j -= pedras[i - 1].peso;
        }
        i--;
    }

    return 0;
}