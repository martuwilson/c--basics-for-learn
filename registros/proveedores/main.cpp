/* 
Escribir un programa que defina una tabla de proveedores. Cada proveedor tiene los datos: nombre, cantidad vendeida, precio unitario (introducido por teclado) e importe (calculado)
visualizar ñps datps de cada proveedor, el importe total y el nombre del proveedor mas caro y el nombre del proveedor mas barato.
*/

#include <iostream>
#include <iomanip> // Para std::setprecision
#include <string>  // Para std::string
#include <limits>  // Para std::numeric_limits

using namespace std;

struct Proveedor {
    char nombre[50];
    int cantidadVendida;
    float precioUnitario;
    float importe; // Calculado
};

void rellenarProveedores(Proveedor proveedores[], int N) {
    for (int i = 0; i < N; i++) {
        cout << "Ingrese el nombre del proveedor " << (i + 1) << ": ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        cin.getline(proveedores[i].nombre, 50);
        cout << "Ingrese la cantidad vendida: ";
        cin >> proveedores[i].cantidadVendida;
        cout << "Ingrese el precio unitario: ";
        cin >> proveedores[i].precioUnitario;
        proveedores[i].importe = proveedores[i].cantidadVendida * proveedores[i].precioUnitario;
    }
}

Proveedor proveedorMasCaro(Proveedor proveedores[], int N) {
    Proveedor proveedorCaro = proveedores[0];
    for (int i = 1; i < N; i++) {
        if (proveedores[i].importe > proveedorCaro.importe) {
            proveedorCaro = proveedores[i];
        }
    }
    return proveedorCaro;
}

Proveedor proveedorMasBarato(Proveedor proveedores[], int N) {
    Proveedor proveedorBarato = proveedores[0];
    for (int i = 1; i < N; i++) {
        if (proveedores[i].importe < proveedorBarato.importe) {
            proveedorBarato = proveedores[i];
        }
    }
    return proveedorBarato;
}

void mostrarProveedores(Proveedor proveedores[], int N) {
    cout << fixed << setprecision(2); // Para mostrar dos decimales
    cout << "Datos de los proveedores:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Proveedor " << (i + 1) << ": " << endl;
        cout << "Nombre: " << proveedores[i].nombre << endl;
        cout << "Cantidad vendida: " << proveedores[i].cantidadVendida << endl;
        cout << "Precio unitario: $" << proveedores[i].precioUnitario << endl;
        cout << "Importe: $" << proveedores[i].importe << endl;
    }
    cout << endl;
}

int main(){
    Proveedor proveedores[30]; // Definimos un arreglo de 30 proveedores
    int N = 5; // Número de proveedores a ingresar

    rellenarProveedores(proveedores, N);
    mostrarProveedores(proveedores, N);

    Proveedor caro = proveedorMasCaro(proveedores, N);
    Proveedor barato = proveedorMasBarato(proveedores, N);

    cout << "Proveedor más caro: " << caro.nombre << " con un importe de $" << caro.importe << endl;
    cout << "Proveedor más barato: " << barato.nombre << " con un importe de $" << barato.importe << endl;

    return 0;
}

