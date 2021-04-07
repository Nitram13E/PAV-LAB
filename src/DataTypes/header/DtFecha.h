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

        int getDia();

        int getMes();

        int getAnio();

        friend std::ostream& operator << (std::ostream&, DtFecha);

        friend bool operator == (DtFecha, DtFecha);
        
        friend bool operator < (DtFecha, DtFecha);

        bool checkFecha(int dia, int mes, int anio);
};

#endif