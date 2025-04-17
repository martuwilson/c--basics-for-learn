#ifndef RESERVA_H
#define RESERVA_H

#include "Usuario.h"
#include "Vuelo.h"
#include "Hotel.h"

class Reserva {
private:
    int id;
    Usuario usuario;
    Vuelo vuelo;
    Hotel hotel;
    int noches;

public:
    Reserva(int id, Usuario usuario, Vuelo vuelo, Hotel hotel, int noches);
    void mostrarResumen() const;
};

#endif
