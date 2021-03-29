#ifndef PUERTO
#define PUERTO
#define MAX_ARRIBO 30
#define CANT_ARRIBOS 0

#include <ostream>
#include <string>

#include "Fecha.h"
#include "Arribo.h"

class DtPuerto
{
    private:
        std::string id;
        std::string nombre;
        DtFecha fechaCreacion;
        int cantArribos;
        
        DtArribo *arribos;
         
    public:
        DtPuerto();
        DtPuerto(std::string, std::string, DtFecha);
        ~DtPuerto();

        void setId(std::string);
        std::string getId();
        
        void setNombre(std::string);
        std::string getNombre();
        
        void setFechaCreacion(DtFecha);
        DtFecha getFechaCreacion();

        void setCantArribos(int);
        int getCantArribos();
};

#endif