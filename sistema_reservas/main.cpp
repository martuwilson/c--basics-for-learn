#include <iostream>
#include <vector>
#include "usuario.h"
#include "vuelo.h"
#include "hotel.h"
#include "reserva.h"

int main() {
    std::vector<Usuario> usuarios = {
        Usuario(1, "Juan", "juan@mail.com"),
        Usuario(2, "Ana", "ana@mail.com")
    };

    std::vector<Vuelo> vuelos = {
        Vuelo(1, "Buenos Aires", "Madrid", "2025-06-01", "10:00", "Aerolíneas Argentinas", 1200, 1200.0),
        Vuelo(2, "Córdoba", "Barcelona", "2025-07-15", "16:30", "Iberia", 150, 950.0)
    };
    

    std::vector<Hotel> hoteles = {
        Hotel(1, "Hotel Madrid Centro", "Madrid", 10, 100.0),
        Hotel(2, "Barcelona Beach Hotel", "Barcelona", 5, 150.0)
    };

    std::vector<Reserva> reservas;

    int opcion;
    do {
        std::cout << "\n===== SISTEMA DE RESERVAS =====\n";
        std::cout << "1. Ver usuarios\n";
        std::cout << "2. Ver vuelos\n";
        std::cout << "3. Ver hoteles\n";
        std::cout << "4. Crear reserva\n";
        std::cout << "5. Ver reservas\n";
        std::cout << "0. Salir\n";
        std::cout << "Opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                for (const auto& u : usuarios) u.mostrarPerfil();
                break;
            case 2:
                for (const auto& v : vuelos) v.mostrarDetalles();
                break;
            case 3:
                for (const auto& h : hoteles) h.mostrarDetalles();
                break;
            case 4: {
                int idU, idV, idH, noches;
                std::cout << "\nSeleccione ID de usuario: ";
                std::cin >> idU;
                std::cout << "Seleccione ID de vuelo: ";
                std::cin >> idV;
                std::cout << "Seleccione ID de hotel: ";
                std::cin >> idH;
                std::cout << "Cantidad de noches: ";
                std::cin >> noches;

                Usuario usuarioSel = usuarios[idU - 1];
                Vuelo vueloSel = vuelos[idV - 1];
                Hotel hotelSel = hoteles[idH - 1];

                Reserva nuevaReserva(reservas.size() + 1, usuarioSel, vueloSel, hotelSel, noches);
                reservas.push_back(nuevaReserva);

                std::cout << "Reserva creada con éxito!\n";
                nuevaReserva.mostrarResumen();
                break;
            }
            case 5:
                for (const auto& r : reservas) r.mostrarResumen();
                break;
            case 0:
                std::cout << "¡Hasta luego!\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }

    } while (opcion != 0);

    return 0;
}
