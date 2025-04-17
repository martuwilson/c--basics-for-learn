#ifndef HOTEL_H
#define HOTEL_H

#include <string>

class Hotel {
private:
    int id;
    std::string nombre;
    std::string ciudad;
    int estrellas;
    double precioPorNoche;

public:
    Hotel(int id, std::string nombre, std::string ciudad, int estrellas, double precioPorNoche);
    void mostrarDetalles() const;

    // Getters
    int getId() const;
    std::string getNombre() const;
    std::string getCiudad() const;
    double getPrecioPorNoche() const;
};

#endif
