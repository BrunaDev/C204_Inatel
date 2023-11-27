#include<iostream>
using namespace std;

struct ponto {
    double x;
    double y;
};

double calcular_area_triangulo(ponto a, ponto b, ponto c) {
    return 0.5 * (
        a.x * b.y - a.y * b.x +
        b.x * c.y - b.y * c.x +
        c.x * a.y - c.y * a.x
    );
}

bool formam_triangulo(ponto a, ponto b, ponto c) {
    // Verifica se os pontos são não colineares
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) != 0;
}

int main() {
	setlocale(LC_ALL, "");
	
    ponto p1, p2, p3;
    double area;

    // Entrada dos pontos
    cout << "Digite as coordenadas do ponto 1 (x y): ";
    cin >> p1.x >> p1.y;

    cout << "Digite as coordenadas do ponto 2 (x y): ";
    cin >> p2.x >> p2.y;

    cout << "Digite as coordenadas do ponto 3 (x y): ";
    cin >> p3.x >> p3.y;

    // Verificar se os pontos formam um triângulo
    if (formam_triangulo(p1, p2, p3)) {
        // Calcular a área do triângulo usando a fórmula fornecida
        area = calcular_area_triangulo(p1, p2, p3);
        cout << "A área do triângulo é: " << area << endl;
    } else {
        cout << "Os pontos não formam um triângulo válido." << endl;
    }
    
    if(area>0){
		cout << "Área positiva => ABC em sentido anti-horário" << endl;
	} else {
		cout << "Área negativa => ABC em sentido horário" << endl;
	}

    return 0;
}