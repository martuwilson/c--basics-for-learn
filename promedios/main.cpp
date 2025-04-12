#include <iostream>
using namespace std;

int main() {
    float nota1, nota2, nota3, promedio;

    // Solicitar al usuario que ingrese las notas
    cout << "Ingrese la primera nota: ";
    cin >> nota1;
    cout << "Ingrese la segunda nota: ";
    cin >> nota2;
    cout << "Ingrese la tercera nota: ";
    cin >> nota3;

    // Calcular el promedio
    promedio = (nota1 + nota2 + nota3) / 3;

    // Mostrar el resultado
    cout << "El promedio es: " << promedio << endl;

    cin.ignore(); // Limpia el '\n' que quedó de cin >>
    cin.get();    // Espera a que presiones Enter

    return 0;
}
