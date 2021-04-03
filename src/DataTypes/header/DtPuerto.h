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

        void setId(std::string);
        std::string getId();
        
        void setNombre(std::string);
        std::string getNombre();
        
        void setFechaCreacion(DtFecha);
        DtFecha getFechaCreacion();

        void setCantArribos(int);
        int getCantArribos();

        friend std::ostream& operator << (std::ostream&, DtPuerto);
};

#endif