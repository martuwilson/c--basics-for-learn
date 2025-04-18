//programa para calcular la distancia entre dos puntos

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float x1, y1, x2, y2, distancia;
    cout << "Ingrese las coordenadas del primer punto (x1 y y1): ";
    cin >> x1 >> y1;
    cout << "Ingrese las coordenadas del segundo punto (x2 y y2): ";
    cin >> x2 >> y2;

    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // sqrt es la raiz cuadrada y pow es la potencia
    cout << "La distancia entre los puntos es: " << distancia << endl;

    return 0;
}