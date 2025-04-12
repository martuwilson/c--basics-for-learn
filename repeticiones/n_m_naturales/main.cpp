//Dados N y M números naturales, informar su producto por sumas sucesivas

#include <iostream>
using namespace std;

int main() {
    int n, m, producto = 0; // Inicializamos el producto en 0

    // Solicitar al usuario que ingrese los números naturales N y M
    cout << "Ingrese el primer número natural (N): ";
    cin >> n;
    cout << "Ingrese el segundo número natural (M): ";
    cin >> m;

    // Calcular el producto utilizando sumas sucesivas
    for (int i = 1; i <= m; i++) {
        producto += n; // Sumar N a sí mismo M veces
    }

    // Mostrar el resultado
    cout << "El producto de " << n << " y " << m << " es: " << producto << endl;

    cin.ignore(); // Limpia el '\n' que quedó de cin >>
    cin.get();    // Espera a que presiones Enter

    return 0;
}