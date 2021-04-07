#ifndef DTPUERTO
#define DTPUERTO
#define MAX_ARRIBO 30
#define CANT_ARRIBOS 0

#include <ostream>
#include <string>

#include "DtFecha.h"

class DtPuerto
{
    private:
        std::string id;
        std::string nombre;
        DtFecha fechaCreacion;
        int cantArribos;
         
    public:
        DtPuerto();
        DtPuerto(std::string, std::string, DtFecha, int);
        ~DtPuerto();

        std::string getId();
        
        std::string getNombre();
        
        DtFecha getFechaCreacion();

        int getCantArribos();

        friend std::ostream& operator << (std::ostream&, DtPuerto);
};

#endif