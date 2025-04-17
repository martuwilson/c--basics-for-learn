#include "Hotel.h"
#include <iostream>

Hotel::Hotel(int id, std::string nombre, std::string ciudad, int estrellas, double precioPorNoche)
    : id(id), nombre(nombre), ciudad(ciudad), estrellas(estrellas), precioPorNoche(precioPorNoche) {}

void Hotel::mostrarDetalles() const {
    std::cout << "ID: " << id
              << " | " << nombre
              << " | " << ciudad
              << " | " << estrellas << " estrellas"
              << " | $" << precioPorNoche << " por noche" << std::endl;
}

int Hotel::getId() const { return id; }
std::string Hotel::getNombre() const { return nombre; }
std::string Hotel::getCiudad() const { return ciudad; }
double Hotel::getPrecioPorNoche() const { return precioPorNoche; }
