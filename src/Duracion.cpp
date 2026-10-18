#include "Duracion.h"
#include <iostream>

Duracion::Duracion(int min, int seg) {
    if (min < 0) min = 0;
    if (seg < 0) seg = 0;

    // Normalización: si los segundos pasan de 59, se convierten en minutos extra
    minutos = min + (seg / 60);
    segundos = seg % 60;
}

int Duracion::getMinutos() const {
    return minutos;
}

int Duracion::getSegundos() const {
    return segundos;
}

int Duracion::totalSegundos() const {
    return (minutos * 60) + segundos;
}

void Duracion::imprimir() const {
    std::cout << minutos << ":" << (segundos < 10 ? "0" : "") << segundos;
}