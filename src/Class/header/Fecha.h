#ifndef FECHA
#define FECHA

#include <iostream>

class Fecha
{
    private:

        int dia;
        int mes;
        int anio;

    public:

        Fecha();
        Fecha(int,int,int);
        
        void setDia(int);
        int getDia();

        void setMes(int);
        int getMes();

        void setAnio(int);
        int getAnio();

        ~Fecha();

        friend std::ostream& operator << (std::ostream&, Fecha);

        friend bool operator == (Fecha, Fecha);
        
        friend bool operator < (Fecha, Fecha);

        bool checkFecha(int dia, int mes, int anio);
};

#endif