#include <iostream>

using namespace std;

struct item
{
    int val;  // valor do item
    int peso; // peso do item
};

int main()
{
    int pd[100][100];     // valor máximo sendo:
                          // olhando do item 'i'->final
                          // olhando uma mochila de capacidade 'j'

    int caminho[100][100]; // utilizado para recuperar quais itens foram escolhidos
                           // 0 -> não pegar o item
                           // 1 -> pegar o item

    int n;            // quantidade de itens
    int capacidade;   // capacidade total da mochila
    item v[100];      // vetor de itens

    // ENTRADA:
    cout << "Entre com a quantidade de itens:" << endl;
    cin >> n;

    cout << "Entre com a capacidade da mochila:" << endl;
    cin >> capacidade;

    for (int i = 0; i < n; i++)
    {
        cout << "Entre com o valor e peso do item: " << i << endl;
        cin >> v[i].val >> v[i].peso;
    }

    // CASO BASE: Inicializar a primeira linha da matriz com zeros.
    for (int j = 0; j <= capacidade; j++)
    {
        pd[0][j] = 0;
        caminho[0][j] = 0;
    }

    // CASO GERAL: Preencher a matriz de programação dinâmica.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= capacidade; j++)
        {
            if (v[i].peso > j)
            {
                // Se o peso do item atual for maior do que a capacidade atual da mochila,
                // não é possível incluir o item, então o valor máximo será o mesmo que antes.
                pd[i][j] = pd[i][j];
                caminho[i][j] = 0;
            }
            else
            {
                // Caso contrário, temos duas opções: pegar o item ou não pegar.
                int escolha1 = pd[i][j]; // Não pegar o item.
                int escolha2 = pd[i][j - v[i].peso] + v[i].val; // Pegar o item.

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

    // observando do item 0->final
	// uma mochila de capacidade igual a 'capacidade'
	cout << "O valor maximo que consigo guardar e " << pd[n][capacidade] << endl;

    // RECUPERAÇÃO
    // Comeca na posicao final
	int i,j;
	i = 0; // do item 0->final
	j = capacidade; // para uma mochila de capacidade max
	
	while(i != n){ // enquanto eu nao chegar no ultimo item
		if(caminho[i][j] == 0) // se nesse momento a melhor opcao foi nao pegar eu nao pego
			i++; // avanco para o proximo i, mantendo a capacidade
		
		else // if(caminho[i][j] == 1) /// se nesse momento a melhor opcao for pegar, eu pego
		{
			cout << "Peguei o item " << i << endl; // indico que peguei o item
			cout << "Peso: " << v[i].peso << endl;
			cout << "Valor: " << v[i].val << endl;
			cout << "---------------------"<< endl;
			j-= v[i].peso; // diminuo a capacidade disponivel
			i++; // avanco para o proximo i
		}
	}
    
    return 0;
}

// int i = n, j = capacidade;
    // while (i > 0 && j > 0)
    // {
    //     if (caminho[i][j] == 1)
    //     {
    //         cout << "---------------------" << endl;
    //         cout << "Peguei o item " << i - 1 << endl;
    //         cout << "Peso: " << v[i - 1].peso << endl;
    //         cout << "Valor: " << v[i - 1].val << endl;
    //         cout << "---------------------" << endl;
    //         j -= v[i - 1].peso;
    //     }
    //     i--;
    // }