#include <iostream>
#include <fstream>
#include <cstring>
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
/* FUNCIONES DEL PROGRAMA */
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

bool existeContacto(char nombre[], char apellido[]){
    Contacto c;
    ifstream entrada; // Se usa ifstream para leer el archivo
    entrada.open(DIR_ARCHIVO, ios::binary); // Abre el archivo en modo binario
    if (entrada.good()){
        while (entrada.read((char*) &c, sizeof(Contacto))){
            /* strcmp = string comparison */
            if (strcmp(c.nombre, nombre) == 0 && strcmp(c.apellido, apellido) == 0){
                // se usa 0 para comparar cadenas, si son iguales devuelve 0, si es menor devuelve -1 y si es mayor devuelve 1
                entrada.close();
                return true; // El contacto existe
            }
        }
        entrada.close();
        return false; // El contacto no existe
    }else{
        cout << "Error al abrir el archivo." << endl;
        entrada.close();
        return false;
    }
}

Contacto buscarContacto(char nombre[], char apellido[]){
    Contacto c;
    ifstream entrada; 
    entrada.open(DIR_ARCHIVO, ios::binary); 
    if (entrada.good()){
        while (entrada.read((char*) &c, sizeof(Contacto))){
            if (strcmp(c.nombre, nombre) == 0 && strcmp(c.apellido, apellido) == 0){
                entrada.close();
                return c; 
            }
        }
    }
}

void mostrarContacto(Contacto c){
    cout << endl;
    cout << "\t\t----------------------------------------" << endl;
    cout << "\t\tNombre: " << c.nombre << endl;
    cout << "\t\tApellido: " << c.apellido << endl;
    cout << "\t\tEdad: " << c.edad << endl;
    cout << "\t\tCorreo: " << c.correo << endl;
    cout << "\t\t----------------------------------------" << endl;
    cout << endl;
}

void listarContacto(){
    ifstream entrada; //entrada significa que se va a leer el archivo
    entrada.open(DIR_ARCHIVO, ios::binary); // Abre el archivo en modo binario

    Contacto c; // Se crea una variable de tipo Contacto para leer los datos del archivo
   if(entrada.good()){
    while(entrada.read((char*) &c, sizeof(Contacto))){ // Lee el archivo hasta que no haya más datos
        mostrarContacto(c);
    }
    entrada.close(); // Cierra el archivo
   }else{
        cout << "Error al abrir el archivo." << endl; // Si no se puede abrir el archivo, muestra un mensaje de error
        entrada.close(); // Cierra el archivo
    }
};

void eliminarContacto(char nombre[],char apellido[]){
    ifstream entrada; // Se usa ifstream para leer el archivo
    ofstream temporal;
    entrada.open(DIR_ARCHIVO, ios::binary); // Abre el archivo en modo binario
    temporal.open("temp.dat", ios::binary); // Abre un archivo temporal para escribir los contactos que no se van a eliminar
    Contacto c;
    if (entrada.good()){
        while (entrada.read((char*) &c, sizeof(Contacto))){
            if (strcmp(c.nombre, nombre) != 0 || strcmp(c.apellido, apellido) != 0){
                // Si el contacto no es el que se va a eliminar, lo escribe en el archivo temporal
                temporal.write(reinterpret_cast<char*>(&c), sizeof(Contacto));
            }
        }
    }
    
    entrada.close(); // Cierra el archivo
    temporal.close(); // Cierra el archivo temporal
    
    remove(DIR_ARCHIVO); // Elimina el archivo original
    rename("temp.dat", DIR_ARCHIVO); // Renombra el archivo temporal al nombre del archivo original
}

void actualizarContacto(char nombre[], char apellido[]){
    ifstream entrada; // Se usa ifstream para leer el archivo
    ofstream temporal;
    entrada.open(DIR_ARCHIVO, ios::binary); 
    temporal.open("temp.dat", ios::binary); 
    Contacto c;
    if (entrada.good()){
        while (entrada.read((char*) &c, sizeof(Contacto))){
            if (strcmp(c.nombre, nombre) == 0 || strcmp(c.apellido, apellido) == 0){
                Contacto nuevoContacto = leerContacto(); // Llama a la función leerContacto para obtener los nuevos datos
                
                temporal.write(reinterpret_cast<char*>(&nuevoContacto), sizeof(Contacto)); // Escribe el nuevo contacto en el archivo temporal
            }else{
                // Si el contacto no es el que se va a actualizar, lo escribe en el archivo temporal
                temporal.write(reinterpret_cast<char*>(&c), sizeof(Contacto));
            }
        }
    }
    
    entrada.close(); // Cierra el archivo
    temporal.close(); // Cierra el archivo temporal
    
    remove(DIR_ARCHIVO); // Elimina el archivo original
    rename("temp.dat", DIR_ARCHIVO); // Renombra el archivo temporal al nombre del archivo original
}
/* FIN FUNCIONES DEL PROGRAMA */


/* FUNCIONES PARA EL MENU */

void menuIngresar(){
    cout << "\t\t\tINGRESO DEL NUEVO CONTACTO" << endl;

    Contacto nuevo = leerContacto(); // Llama a la función leerContacto para obtener los datos del nuevo contacto
    if (!existeContacto(nuevo.nombre, nuevo.apellido)) {
        ingresarContacto(nuevo); // Llama a la función ingresarContacto para guardar el nuevo contacto
        cout << "\t\t\tContacto ingresado correctamente." << endl;
    } else {
        cout << "\t\t\tEl contacto ya existe." << endl;
    }

};
void menuBuscar(){
    cout << "\t\t\tBUSQUEDA DE CONTACTO" << endl;
    char nombre[30], apellido[45];
    cout << "\t\tNombre: ";
    cin.getline(nombre, 30);
    cout << "\t\tApellido: ";
    cin.getline(apellido, 45);
    
    if (existeContacto(nombre, apellido)) {
        Contacto c = buscarContacto(nombre, apellido); // Llama a la función buscarContacto para obtener los datos del contacto
        mostrarContacto(c); // Llama a la función mostrarContacto para mostrar los datos del contacto
    } else {
        cout << "\t\tEl contacto no existe." << endl;
    }

};
void menuListar(){
    cout << "\t\t\tLISTA DE CONTACTOS" << endl;
    listarContacto(); // Llama a la función listarContacto para mostrar todos los contactos
};
void menuEliminar(){
    cout << "\t\t\tELIMINAR CONTACTO" << endl;
    char nombre[30], apellido[45];
    cout << "\t\tNombre: ";
    cin.getline(nombre, 30);
    cout << "\t\tApellido: ";
    cin.getline(apellido, 45);
    
    if (existeContacto(nombre, apellido)) {
        eliminarContacto(nombre, apellido); // Llama a la función eliminarContacto para eliminar el contacto
        cout << "\t\t\tContacto eliminado correctamente." << endl;
    } else {
        cout << "\t\tEl contacto no existe." << endl;
    }
};
void menuActualizar(){
    cout << "\t\t\tACTUALIZAR CONTACTO" << endl;
    char nombre[30], apellido[45];
    cout << "\t\tNombre: ";
    cin.getline(nombre, 30);
    cout << "\t\tApellido: ";
    cin.getline(apellido, 45);
    
    if (existeContacto(nombre, apellido)) {
        actualizarContacto(nombre, apellido); // Llama a la función actualizarContacto para actualizar el contacto
        cout << "\t\t\tContacto actualizado correctamente." << endl;
    } else {
        cout << "\t\tEl contacto no existe." << endl;
    }
};


/* FIN  FUNCIONES PARA EL MENU */

int main () {
 /* Contacto c = leerContacto();
 ingresarContacto(c); */
/*  if(existeContacto("","")){
    Contacto c = buscarContacto("","");
    mostrarContacto(c);
 }else{
    cout << "El contacto no existe." << endl;
 } */
//listarContacto(); // Llama a la función listarContacto para mostrar todos los contactos
//eliminarContacto("",""); // Llama a la función eliminarContacto para eliminar un contacto
//listarContacto(); // Llama a la función listarContacto para mostrar todos los contactos después de eliminar uno

//actualizarContacto("",""); // Llama a la función actualizarContacto para actualizar un contacto
listarContacto(); // Llama a la función listarContacto para mostrar todos los contactos después de actualizar uno
 return 0;
}

