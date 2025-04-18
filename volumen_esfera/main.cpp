// programa que calcula el volumen de una esfera

#include <iostream>
#include <cmath> // Para usar la constante M_PI
using namespace std;

int main() {
    float radio, volumen;
    cout << "Ingrese el radio de la esfera: ";
    cin >> radio; 
    volumen = (4.0 / 3.0) * M_PI * pow(radio, 3); // M_PI es la constante de pi
    cout << "El volumen de la esfera es: " << volumen << endl;
    return 0;
}