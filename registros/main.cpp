#include <iostream>
using namespace std;

struct Persona //struct es una palabra reservada que se utiliza para definir un nuevo tipo de dato llamado estructura
// en C++. Una estructura es un tipo de dato compuesto que permite agrupar diferentes tipos de datos bajo un mismo nombre.
{
    char nombre[50];
    char apellido[50];
    int edad;
};

int main()
{
    /* Registros */
    Persona p; // Declaración de la variable p de tipo Persona
    cout << "Ingrese el nombre: ";
    cin.getline(p.nombre, 50);
    cout << "Ingrese el apellido: ";
    cin.getline(p.apellido, 50);
    cout << "Ingrese la edad: ";
    cin >> p.edad;
    cout << "Los datos ingresados son: " << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Apellido: " << p.apellido << endl;
    cout << "Edad: " << p.edad << endl;
    
    return 0;
}
