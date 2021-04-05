#ifndef DTARRIBO
#define DTARRIBO

#include "DtFecha.h"
#include "DtBarco.h"

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
        
        void setFecha(DtFecha);
        DtFecha getFecha();
        

        void setCarga(float);
        float getCarga(); 

        void setBarco(DtBarco*);
        DtBarco* getBarco();

        
};

#endif