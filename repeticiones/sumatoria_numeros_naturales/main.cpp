// informar los primeros 100 numeros naturales y su suma
#include <iostream>
using namespace std;

int main() {
    int suma = 0; // Variable para almacenar la suma de los números
    int limite = 100; // Limite superior de la suma

    cout << "Los primeros " << limite << " números naturales son:" << endl;

    // Bucle para imprimir los números y calcular la suma
    for (int i = 1; i <= limite; i++) {
        cout << i << " "; // Imprimir el número actual
        suma += i; // Sumar el número actual a la suma total
    }

    cout << endl; // Nueva línea después de imprimir los números
    cout << "La suma de los primeros " << limite << " números naturales es: " << suma << endl;

    cin.ignore(); // Limpia el '\n' que quedó de cin >>
    cin.get();    // Espera a que presiones Enter

    return 0;
}