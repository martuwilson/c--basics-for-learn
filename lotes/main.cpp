#include <iostream>
#include <limits> // Para std::numeric_limits

using namespace std;

int main() {
    int valor, suma = 0, cantidad = 0, totalSublotes = 0;
    int maximoGlobal = std::numeric_limits<int>::min();
    int subloteMaximo = 0, posicionMaximo = 0;
    int minimoSublote = 0;
    bool primerValor = true; // Para manejar el minimo del sublote

    cout << "Ingrese valores enteros positivos (finaliza con un numero negativo):" << endl;

    int posicionRelativa = 0; // Posicion relativa dentro del sublote
    int posicionMaxRelativa = 0; // Posicion relativa del maximo dentro del sublote actual
    int subloteActual = 0; // Numero del sublote actual

    while (true) {
        cin >> valor;

        if (valor < 0) {
            // Fin del lote
            break;
        }

        if (valor == 0) {
            // Fin del sublote
            if (cantidad > 0) {
                // Calcular y mostrar el promedio del sublote
                cout << "Promedio del sublote " << subloteActual + 1 << ": " << (float)suma / cantidad << endl;
                cout << "Valor minimo del sublote " << subloteActual + 1 << ": " << minimoSublote << endl;
            } else {
                cout << "Sublote " << subloteActual + 1 << " vacio." << endl;
            }

            // Reiniciar variables para el siguiente sublote
            suma = 0;
            cantidad = 0;
            primerValor = true;
            posicionRelativa = 0;
            subloteActual++;
            totalSublotes++;
            continue;
        }

        // Procesar el valor dentro del sublote
        suma += valor;
        cantidad++;
        posicionRelativa++;

        // Actualizar el minimo del sublote
        if (primerValor || valor < minimoSublote) {
            minimoSublote = valor;
            primerValor = false;
        }

        // Actualizar el maximo global
        if (valor > maximoGlobal) {
            maximoGlobal = valor;
            subloteMaximo = subloteActual + 1;
            posicionMaxRelativa = posicionRelativa;
        }
    }

    // Procesar el ultimo sublote si no termino con un cero
    if (cantidad > 0) {
        cout << "Promedio del sublote " << subloteActual + 1 << ": " << (float)suma / cantidad << endl;
        cout << "Valor minimo del sublote " << subloteActual + 1 << ": " << minimoSublote << endl;
        totalSublotes++;
    }

    // Mostrar resultados finales
    cout << "Total de sublotes procesados: " << totalSublotes << endl;
    if (maximoGlobal != std::numeric_limits<int>::min()) {
        cout << "Valor maximo del conjunto: " << maximoGlobal << endl;
        cout << "Encontrado en el sublote " << subloteMaximo << ", posicion relativa " << posicionMaxRelativa << endl;
    } else {
        cout << "No se ingresaron valores validos." << endl;
    }

    return 0;
}