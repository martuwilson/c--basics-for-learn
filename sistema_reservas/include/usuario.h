#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
public:
    int id;
    std::string nombre;
    std::string email;

    Usuario(int id, std::string nombre, std::string email);
    void mostrarPerfil() const;
};

#endif
