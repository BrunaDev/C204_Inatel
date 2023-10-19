#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double raiz(double x, double x0, double e) {
    if (fabs(x0 * x0 - x) <= e) {
        return x0;
    } else {
        double novo_x0 = 0.5 * (x0 + x / x0);
        return raiz(x, novo_x0, e);
    }
}

int main() {
    double x, x0, e;
    
    //cout << "Digite o valor de x: ";
    cin >> x;
    
    //cout << "Digite uma estimativa inicial x0: ";
    cin >> x0;
    
    //cout << "Digite o valor de e (limitante): ";
    cin >> e;
    
    double resultado = raiz(x, x0, e);
    
    cout << fixed << setprecision(4);
    cout << resultado << endl;
    
    return 0;
}