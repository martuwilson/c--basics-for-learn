//Se realiza una inspeccion en una fábrica de pinturas, y se detectaron 20 infracciones. De cada infraccion se tomo nota de los siguientes datos:
//- Tipo de Infraccion (1, 2, 3, o 4)
//- Motivo de la infraccion
//- Valor de la multa
//- Gravedad de la infraccion (‘L’,‘M’, ‘G’)
//Se pide informar al final del proceso:
//• Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
//• La leyenda “Clausurar fábrica” si la cantidad de infracciones 3 y 4 con gravedad “G” sean mayores a 3.

#include <iostream>
#include <string>
#include <iomanip> // Para std::fixed y std::setprecision

using namespace std;

int main() {
    const int NUM_INFRACCIONES = 20; // Número total de infracciones
    int tipoInfraccion[NUM_INFRACCIONES]; // Arreglo para almacenar los tipos de infraccion
    string motivoInfraccion[NUM_INFRACCIONES]; // Arreglo para almacenar los motivos de la infraccion
    float valorMulta[NUM_INFRACCIONES]; // Arreglo para almacenar los valores de las multas
    char gravedadInfraccion[NUM_INFRACCIONES]; // Arreglo para almacenar las gravidades de las infracciones

    // Variables para almacenar los totales de las multas por gravedad
    int totalGravedadL = 0;
    int totalGravedadM = 0;
    int totalGravedadG = 0;

    // Contador para la cantidad de infracciones 3 y 4 con gravedad "G"
    int contadorInfraccionesG = 0;

    // Ingreso de datos
    for (int i = 0; i < NUM_INFRACCIONES; i++) {
        std::cout << "Ingrese el tipo de infraccion (1, 2, 3, o 4) para la infraccion " << (i + 1) << ": ";
        std::cin >> tipoInfraccion[i];
        std::cout << "Ingrese el motivo de la infraccion: ";
        std::cin.ignore(); // Limpiar el buffer antes de usar getline
        getline(std::cin, motivoInfraccion[i]);
        std::cout << "Ingrese el valor de la multa: ";
        std::cin >> valorMulta[i];
        std::cout << "Ingrese la gravedad de la infraccion (L, M, G): ";
        std::cin >> gravedadInfraccion[i];

        // Acumulacion de totales según gravedad
        switch (gravedadInfraccion[i]) {
            case 'L':
                totalGravedadL += static_cast<int>(valorMulta[i]); // Convertir a int
                break;
            case 'M':
                totalGravedadM += static_cast<int>(valorMulta[i]); // Convertir a int
                break;
            case 'G':
                totalGravedadG += static_cast<int>(valorMulta[i]); // Convertir a int
                if (tipoInfraccion[i] == 3 || tipoInfraccion[i] == 4) {
                    contadorInfraccionesG++; // Contar infracciones 3 y 4 con gravedad G
                    //Condicion para cortar ejecucion cuando hay 3 infracciones G
                    if (contadorInfraccionesG >= 3) {
                        std::cout << "Clausurar fabrica" << endl;
                        return 0;
                    }
                }
                break;
                
            default:
                std::cout << "Gravedad inválida. Debe ser L, M o G." << endl;
                i--; // Decrementar i para repetir la iteracion actual
                break;
        }
    }

    // Mostrar los totales de las multas por gravedad
    cout << fixed << setprecision(2); // Configurar la salida para mostrar dos decimales
    cout << "Total de multas con gravedad L: $" << totalGravedadL << endl;
    cout << "Total de multas con gravedad M: $" << totalGravedadM << endl;
    cout << "Total de multas con gravedad G: $" << totalGravedadG << endl;

    // Verificar si se debe clausurar la fábrica
    if (contadorInfraccionesG >= 3) {
        cout << "Clausurar fábrica" << endl;
    }

    cin.ignore(); // Limpiar el buffer antes de esperar entrada del usuario
    cin.get(); // Esperar a que el usuario presione Enter

    return 0;
}

// Fin del programa
