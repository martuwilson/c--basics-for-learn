#include <iostream>
#include <vector>
#include "usuario.h"
#include "vuelo.h"

int main() {
    std::vector<Usuario> usuarios;
    std::vector<Vuelo> vuelos;

    // Usuarios dummy
    usuarios.emplace_back(1, "Juan Perez", "juan@email.com");

    // Vuelos dummy
    vuelos.emplace_back(1, "Buenos Aires", "Madrid", "2025-05-01", "10:00", "Aerolineas", 120, 1500.0);
    vuelos.emplace_back(2, "Córdoba", "Miami", "2025-05-05", "15:30", "Latam", 80, 1300.0);

    int opcion;
    do {
        std::cout << "\n--- Sistema de Reservas Aereas ---\n";
        std::cout << "1. Listar usuarios\n";
        std::cout << "2. Listar vuelos\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                for (const auto& u : usuarios)
                    u.mostrarPerfil();
                break;
            case 2:
                for (const auto& v : vuelos)
                    v.mostrarDetalles();
                break;
            case 0:
                std::cout << "Saliendo del sistema.\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }

    } while (opcion != 0);

    return 0;
}
