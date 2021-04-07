#ifndef DTBARCOPASAJERO
#define DTBARCOPASAJERO

#include <iostream>
#include "../DtBarco.h"
#include "../TipoTamanio.h"

class DtBarcoPasajero : public DtBarco
{
    private:
        int cantPasajeros;
        TipoTamanio tamanio;

    public:
        DtBarcoPasajero();
        DtBarcoPasajero(std::string id, std::string nombre, int cantPasajeros, TipoTamanio tamanio);

        int getCantPasajeros();

        TipoTamanio getTamanio();

        friend std::ostream& operator << (std::ostream&, DtBarcoPasajero);
};


#endif