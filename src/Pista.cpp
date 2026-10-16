
#include "Pista.h"

#include <iostream>

// Constructor de Pista
Pista::Pista(const std::string& titulo, int min, int seg)
    : titulo(titulo), duracion(min, seg) {

    if (this->titulo.empty()) {
        this->titulo = "Sin título";
    }
}

std::string Pista::getTitulo() const {
    return titulo;
}

Duracion Pista::getDuracion() const {
    return duracion;
}

// Modifica el título
void Pista::setTitulo(const std::string& nuevoTitulo) {
   
