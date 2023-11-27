#include<iostream>
using namespace std;

struct ponto {
    int x;
    int y;
};

int area_triangulo(ponto a, ponto b, ponto p) {
    return (a.x * (b.y - p.y) + b.x * (p.y - a.y) + p.x * (a.y - b.y));
}

// Retorna:
//  1 se p estiver à esquerda de ab,
// -1 se p estiver à direita,
//  0 se estiver alinhado
int lado(ponto a, ponto b, ponto p) {
    int area = area_triangulo(a, b, p);
    if (area > 0) {
        return 1; // à esquerda
    } else if (area < 0) {
        return -1; // à direita
    } else {
        return 0; // alinhado
    }
}

int main() {
	setlocale(LC_ALL, "");
	
    ponto a, b, p;

    // Entrada dos pontos A, B e P
    cout << "Digite as coordenadas do ponto A (x y): ";
    cin >> a.x >> a.y;

    cout << "Digite as coordenadas do ponto B (x y): ";
    cin >> b.x >> b.y;

    cout << "Digite as coordenadas do ponto P (x y): ";
    cin >> p.x >> p.y;

    // Verificar a relação entre o ponto P e o segmento AB
    int resultado = lado(a, b, p);

    // Exibir o resultado
    if (resultado == 1) {
        cout << "O ponto P está à esquerda do segmento AB." << endl;
    } else if (resultado == -1) {
        cout << "O ponto P está à direita do segmento AB." << endl;
    } else {
        cout << "O ponto P está alinhado com o segmento AB." << endl;
    }

    return 0;
}