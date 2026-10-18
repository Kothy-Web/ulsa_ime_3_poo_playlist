#include <iostream>
#include "Duracion.h"
#include "Cancion.h"
#include "Podcast.h"
#include "Playlist.h"

int main() {
    std::cout << "=== PRUEBA DEL SISTEMA DE PLAYLISTS ===\n" << std::endl;

    // 1. Crear biblioteca de pistas
    Cancion c1("Bohemian Rhapsody", 5, 55, "Queen", "Rock");
    Cancion c2("Stairway to Heaven", 8, 2, "Led Zeppelin", "Rock");
    Cancion c3("Blinding Lights", 3, 20, "The Weeknd", "Synthwave");

    Podcast p1("Tech Talk #42", 45, 10, "Alex Dev", 42);
    Podcast p2("Historia del Rock", 30, 0, "Maria Rocker", 5);

    // 2. Crear Playlists
    Playlist plRock("Rock Clasico");
    Playlist plMix("Mix Variado");

    // 3. Agregar pistas a las playlists
    plRock.agregarCancion(&c1);
    plRock.agregarCancion(&c2);
    plRock.agregarCancion(&c3);

    // Pruebas de casos límite (duplicado y nullptr)
    std::cout << "Agregando c1 duplicada (esperado 0/false): " << plRock.agregarCancion(&c1) << std::endl;
    std::cout << "Agregando nullptr (esperado 0/false): " << plRock.agregarCancion(nullptr) << std::endl;

    plMix.agregarCancion(&c1); // La misma canción en otra playlist (agregación)
    plMix.agregarPodcast(&p1);
    plMix.agregarPodcast(&p2);

    // 4. Mostrar contenido de las playlists
    std::cout << "\n";
    plRock.mostrar();
    std::cout << "\n";
    plMix.mostrar();

    // 5. Demostración de punteros (Experimento 3)
    std::cout << "\n--- Modificando el titulo de c1 ---" << std::endl;
    c1.setTitulo("Bohemian Rhapsody (Remastered)");

    // Al imprimirse de nuevo, se refleja el cambio en ambas playlists porque guardan punteros
    std::cout << "\nDespues de modificar la cancion original:" << std::endl;
    plRock.mostrar();

    return 0;
}
