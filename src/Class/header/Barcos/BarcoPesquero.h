#ifndef BARCOPESQUERO
#define BARCOPESQUERO

#define MAX_CARGA 50
#include <iostream>
#include "../Barco.h"
#include "../../../DataTypes/header/Barcos/DtBarcoPesquero.h"

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

        void partir(float);

        DtBarco* getDtBarco();
};

#endif