#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

string atributos_base[3] = {"Mental", "Físico", "Espiritual"};

typedef struct habilidade {
    int codigo;
    string descricao;
    int atributo_base;
    int modificador;
} Habilidade;

typedef struct desafio {
    int dificuldade;
    int atributo_base;
} Desafio;

Desafio gerar_desafio() {
    Desafio d;
    d.dificuldade = rand() % 30;
    d.atributo_base = rand() % 3;
    return d;
}

int rolar_d20() {
    return rand() % 20;
}

int main() {
    setlocale(LC_ALL, "");

	cout << "------------------x------------------" << endl;
    cout << "Bem-vindo ao sistema de habilidades!";

    int op = 4;
    vector<Habilidade> habilidades;

    do {
        cout << "\n\t\tMenu\n\t1> Cadastrar nova habilidade\n\t2> Testar habilidades\n\n\t3> Sair\n";

        do {
            cout << "Entre com a opção desejada: ";
            cin >> op;
            if (op != 1 && op != 2 && op != 3)
                cout << "Opção inválida!" << endl;
        } while (op != 1 && op != 2 && op != 3);

        if (op == 1) {
        	cout << "------------------x------------------" << endl;
            // ----Cadastrar habilidade----
            cout << "\n\tCadastro de habilidade" << endl;

            Habilidade nova_habilidade;
            cout << "Informe o código: ";
            cin >> nova_habilidade.codigo;
            cin.ignore(); // Consumir a nova linha após o código

            cout << "Informe a descrição: ";
            getline(cin, nova_habilidade.descricao);

            cout << "Informe o atributo base (1>Mental, 2>Físico, 3>Espiritual): ";
            cin >> nova_habilidade.atributo_base;

            cout << "Informe o modificador: ";
            cin >> nova_habilidade.modificador;

            habilidades.push_back(nova_habilidade);

        } else if (op == 2) {
        	cout << "------------------x------------------" << endl;
            cout << "\n\tTeste de habilidade" << endl;
            Desafio d = gerar_desafio();
            cout << "Desafio enfrentado: " << atributos_base[d.atributo_base] << endl;

            int habilidade_escolhida;
            Habilidade habilidade_testada;
            
            do {
            	cout << "Escolha a sua habilidade (código): ";
            	cin >> habilidade_escolhida;

            	bool habilidade_encontrada = false;

            	for (int i=0; i<habilidades.size(); i++) {
    				   	if (habilidades[i].codigo == habilidade_escolhida) {
        				  		habilidade_testada = habilidades[i];
        				  		habilidade_encontrada = true;
        			  		break;
    			   		}
				}

            	if (!habilidade_encontrada) {
    				cout << "Habilidade não encontrada." << endl;
				} else if (habilidade_testada.atributo_base == d.atributo_base) {
    				int valor_aleatorio = rolar_d20();
    				int valor_final = valor_aleatorio + habilidade_testada.modificador;

    		   		cout << "Valor gerado no dado (d20): " << valor_aleatorio << endl;
    				cout << "Valor final (d20 + modificador): " << valor_final << endl;

    				if (valor_final >= d.dificuldade) {
        			cout << "Você superou esse desafio!" << endl;
    				} else {
        			cout << "Você fracassou nesse desafio..." << endl;
    				}
				} else {
    			   	cout << "Essa habilidade não pode ser usada para esse desafio." << endl;
				}
			} while(habilidade_testada.atributo_base != d.atributo_base);
        }

    } while (op != 3);

    cout << "Obrigado por utilizar o sistema de habilidades!" << endl;

    return 0;
}