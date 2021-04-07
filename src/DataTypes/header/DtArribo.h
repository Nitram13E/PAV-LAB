#ifndef DTARRIBO
#define DTARRIBO

#include "DtFecha.h"
#include "Barcos/DtBarcoPasajero.h"
#include "Barcos/DtBarcoPesquero.h"

class DtArribo
{
    private:
        DtFecha fecha;
        float carga;
        DtBarco *barco;

    public:
        DtArribo();
        DtArribo(DtFecha, float, DtBarco*);
        ~DtArribo();

        DtFecha getFecha();
        

        float getCarga(); 

        DtBarco* getBarco();

        friend std::ostream& operator << (std::ostream&, DtArribo);
        
};

#endif