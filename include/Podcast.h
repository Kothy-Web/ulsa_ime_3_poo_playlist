#ifndef PODCAST_H
#define PODCAST_H

#include <string>
#include "Pista.h"

class Podcast : public Pista {
private:
    std::string anfitrion;
    int numeroEpisodio;

public:
    Podcast(const std::string& titulo, int min, int seg,
            const std::string& anfitrion, int numeroEpisodio);

    std::string getAnfitrion() const;
    int getNumeroEpisodio() const;

    void mostrar() const;
};

#endif
