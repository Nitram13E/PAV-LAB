#ifndef DTFECHA
#define DTFECHA

#include <iostream>

class DtFecha
{
    private:

        int dia;
        int mes;
        int anio;

    public:

        DtFecha();
        DtFecha(int,int,int);
        ~DtFecha();

        void setDia(int dia);
        int getDia();

        void setMes(int mes);
        int getMes();
        
        void setAnio(int anio);
        int getAnio();

        friend std::ostream& operator << (std::ostream&, DtFecha);

        friend bool operator == (DtFecha, DtFecha);
        
        friend bool operator < (DtFecha, DtFecha);

        bool checkFecha(int dia, int mes, int anio);
};

#endif