#include "Reserva.h"
#include <iostream>

Reserva::Reserva(int id, Usuario usuario, Vuelo vuelo, Hotel hotel, int noches)
    : id(id), usuario(usuario), vuelo(vuelo), hotel(hotel), noches(noches) {}

void Reserva::mostrarResumen() const {
    std::cout << "\n--- RESERVA #" << id << " ---" << std::endl;
    usuario.mostrarPerfil();
    vuelo.mostrarDetalles();
    hotel.mostrarDetalles();
    std::cout << "Noches: " << noches << std::endl;
    std::cout << "Total: $" << (vuelo.getPrecio() + hotel.getPrecioPorNoche() * noches) << std::endl;
}
