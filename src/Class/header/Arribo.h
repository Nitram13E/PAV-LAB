#ifndef ARRIBO
#define ARRIBO

#include "../../DataTypes/header/DtFecha.h"
#include "Barco.h"

class Arribo
{
    private:
        DtFecha fecha;
        float carga;
        Barco *barco;

    public:
        Arribo();
        Arribo(DtFecha, float, Barco*);
        ~Arribo();

        void setFecha(DtFecha);
        DtFecha getFecha();
        
        void setCarga(float);
        float getCarga(); 

        void setBarco(Barco*);
        Barco* getBarco(); 
};

#endif