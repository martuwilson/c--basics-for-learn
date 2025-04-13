#include <iostream>
#include <fstream>
//#define DIR_ARCHIVO "contactos.dat" //OPCION 1
using namespace std;

const char DIR_ARCHIVO[] = "contactos.dat"; //OPCION 2
const int MAX_CONTACTOS = 1000;

struct Contacto {
    char nombre[30];
    char apellido[45];
    int edad;
    char correo[45];
};

void ingresarContacto(Contacto c){
    ofstream salida;
    salida.open(DIR_ARCHIVO, ios::binary | ios::app); // Abre el archivo en modo binario y de append
    // Se usa ios::app para agregar al final del archivo sin sobrescribir
    if (!salida) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    salida.write(reinterpret_cast<char*>(&c), sizeof(Contacto));
    salida.close();
}

Contacto leerContacto(){
    Contacto c;
    cout<<"\t\tNombre: ";
    cin.getline(c.nombre, 30);
    cout<<"\t\tApellido: ";
    cin.getline(c.apellido, 45);
    cout<<"\t\tEdad: ";
    cin>>c.edad;
    cin.ignore(); // Limpiar el buffer de entrada , se usa post valor numerico
    cout<<"\t\tCorreo: ";
    cin.getline(c.correo, 45);
    return c;
}

int main () {
 /* Agenda de contactos */
 /* Ingresar contacto,
 Buscar contacto,
 ver lista de contactos,
 eliminar contacto,
 actualizar contacto,
 */

 Contacto c = leerContacto();
 ingresarContacto(c);
 return 0;
}