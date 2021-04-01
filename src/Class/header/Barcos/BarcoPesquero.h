#ifndef BARCOPESQUERO
#define BARCOPESQUERO

#include <iostream>
#include "../Barco.h"

class BarcoPesquero : public Barco
{
    private:
        int capacidad;
        int carga;

    public:
        BarcoPesquero();
        BarcoPesquero(std::string id, std::string nombre, int capacidad, int carga);

        void setCapacidad(int);
        int getCapacidad();

        void setCarga(int);
        int getCarga();

        void arribar(float);
};

#endif