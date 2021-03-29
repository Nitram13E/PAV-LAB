#ifndef ARRIBO
#define ARRIBO

#include "Fecha.h"
#include "Barco.h"

class DtArribo
{
    private:
        DtFecha fecha;
        float carga;
        DtBarco *barco;

    public:
        DtArribo();
        DtArribo(DtFecha, float, DtBarco*);
        
        void setFecha(DtFecha);
        DtFecha getFecha();
        

        void setCarga(float);
        float getCarga(); 

        void setBarco(DtBarco*);
        DtBarco* getBarco();

        ~DtArribo();
};

#endif