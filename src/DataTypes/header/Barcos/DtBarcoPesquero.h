#ifndef DTBARCOPESQUERO
#define DTBARCOPESQUERO

#include "../DtBarco.h"

class DtBarcoPesquero : public DtBarco
{
    private:
        int capacidad;
        int carga;

    public:
        DtBarcoPesquero();
        DtBarcoPesquero(std::string id, std::string nombre, int capacidad, int carga);

        void setCapacidad(int);
        int getCapacidad();

        void setCarga(int);
        int getCarga();

        friend std::ostream& operator << (std::ostream&, DtBarcoPesquero);
};

#endif