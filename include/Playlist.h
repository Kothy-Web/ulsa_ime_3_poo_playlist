#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Cancion.h"
#include "Podcast.h"

class Playlist {
private:
    std::string nombre;
    std::vector<Cancion*> canciones;
    std::vector<Podcast*> podcasts;

public:
    Playlist(const std::string& nombre);

    std::string getNombre() const;

    bool agregarCancion(Cancion* c);
    bool agregarPodcast(Podcast* p);

    int cantidadPistas() const;
    Duracion duracionTotal() const;
    void mostrar() const;
};

#endif
