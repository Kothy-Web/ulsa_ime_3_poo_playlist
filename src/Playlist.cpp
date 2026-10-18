#include "Playlist.h"
#include <iostream>

Playlist::Playlist(const std::string& nombre) : nombre(nombre) {}

std::string Playlist::getNombre() const {
    return nombre;
}

bool Playlist::agregarCancion(Cancion* c) {
    if (c == nullptr) return false;
    // Evitar duplicados
    for (const auto& cancion : canciones) {
        if (cancion == c) return false;
    }
    canciones.push_back(c);
    return true;
}

bool Playlist::agregarPodcast(Podcast* p) {
    if (p == nullptr) return false;
    // Evitar duplicados
    for (const auto& podcast : podcasts) {
        if (podcast == p) return false;
    }
    podcasts.push_back(p);
    return true;
}

int Playlist::cantidadPistas() const {
    return static_cast<int>(canciones.size() + podcasts.size());
}

Duracion Playlist::duracionTotal() const {
    int totalSegs = 0;
    for (const auto& c : canciones) {
        totalSegs += c->getDuracion().totalSegundos();
    }
    for (const auto& p : podcasts) {
        totalSegs += p->getDuracion().totalSegundos();
    }
    return Duracion(totalSegs / 60, totalSegs % 60);
}

void Playlist::mostrar() const {
    std::cout << "========================================" << std::endl;
    std::cout << "Playlist: " << nombre << std::endl;
    std::cout << "Total de pistas: " << cantidadPistas() << " | Duración total: ";
    duracionTotal().imprimir();
    std::cout << "\n----------------------------------------" << std::endl;

    if (!canciones.empty()) {
        std::cout << "Canciones:\n";
        for (size_t i = 0; i < canciones.size(); ++i) {
            std::cout << "  " << (i + 1) << ". ";
            canciones[i]->mostrar();
        }
    }

    if (!podcasts.empty()) {
        std::cout << "Podcasts:\n";
        for (size_t i = 0; i < podcasts.size(); ++i) {
            std::cout << "  " << (i + 1) << ". ";
            podcasts[i]->mostrar();
        }
    }
    std::cout << "========================================" << std::endl;
}