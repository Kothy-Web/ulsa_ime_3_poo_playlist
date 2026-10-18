#ifndef DURACION_H
#define DURACION_H

class Duracion {
private:
    int minutos;
    int segundos;

public:
    Duracion(int min = 0, int seg = 0);

    int getMinutos() const;
    int getSegundos() const;

    int totalSegundos() const;
    void imprimir() const;
};

#endif
