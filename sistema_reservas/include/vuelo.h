#ifndef VUELO_H
#define VUELO_H

#include <string>

class Vuelo {
public:
    int id;
    std::string origen, destino, fecha, hora;
    std::string aerolinea;
    int asientosDisponibles;
    double precio;

    Vuelo(int id, std::string origen, std::string destino, std::string fecha,
          std::string hora, std::string aerolinea, int asientos, double precio);
    void mostrarDetalles() const;

    double getPrecio() const;
};

#endif
