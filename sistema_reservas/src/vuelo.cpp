#include "Vuelo.h"
#include <iostream>

Vuelo::Vuelo(int id, std::string origen, std::string destino, std::string fecha,
             std::string hora, std::string aerolinea, int asientos, double precio)
    : id(id), origen(origen), destino(destino), fecha(fecha), hora(hora),
      aerolinea(aerolinea), asientosDisponibles(asientos), precio(precio) {}

void Vuelo::mostrarDetalles() const {
    std::cout << "Vuelo #" << id << ": " << origen << " -> " << destino
              << " el " << fecha << " a las " << hora << " | Aerolínea: "
              << aerolinea << " | $" << precio << " | Asientos: "
              << asientosDisponibles << std::endl;
}
