//En un estacionamiento cobran $1.50 la hora o fraccion. Diseñar el programa que calcule el costo de un estacionamiento, dado el tiempo en horas y minutos.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int horas, minutos;
    float costo, totalHoras;

    cout << "Ingrese el tiempo de estacionamiento (horas y minutos): ";
    cin >> horas >> minutos;

    // Convertir el tiempo total a horas
    totalHoras = horas + (minutos / 60.0);

    // Calcular el costo
    costo = ceil(totalHoras) * 1.50; // ceil redondea hacia arriba

    cout << "El costo del estacionamiento es: $" << costo << endl;

    return 0;
}