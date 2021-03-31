#ifndef BARCOPASAJERO
#define BARCOPASAJERO

#include "../Barco.h"
#include "../../DataTypes/header/TipoTamanio.h"

class BarcoPasajero : public Barco
{
    private:
        int cantPasajeros;
        TipoTamanio tamanio;

    public:
        BarcoPasajero();
        BarcoPasajero(std::string id, std::string nombre, int cantPasajeros, TipoTamanio tamanio);

        void setCantPasajeros(int);
        int getCantPasajeros();

        void setTamanio(TipoTamanio);
        TipoTamanio getTamanio();

        void arribar(float);
};


#endif