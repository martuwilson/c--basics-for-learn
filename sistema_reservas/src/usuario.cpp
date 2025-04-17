#include "Usuario.h"
#include <iostream>

Usuario::Usuario(int id, std::string nombre, std::string email)
    : id(id), nombre(nombre), email(email) {}

void Usuario::mostrarPerfil() const {
    std::cout << "Usuario #" << id << " - " << nombre << " (" << email << ")" << std::endl;
}
