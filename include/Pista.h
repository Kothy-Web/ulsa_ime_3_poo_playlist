#ifndef PISTA_H
#define PISTA_H

#include <string>
#include "Duracion.h"

class Pista {
private:
    std::string titulo;
    Duracion duracion;

public:
    Pista(const std::string& titulo, int min, int seg);
    virtual ~Pista() = default;

    std::string getTitulo() const;
    Duracion getDuracion() const;

    void setTitulo(const std::string& nuevoTitulo);
    virtual void mostrarInfo() const;
};

#endif