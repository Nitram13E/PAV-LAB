#ifndef PUERTO
#define PUERTO
#define MAX_ARRIBO 30
#define CANT_ARRIBOS 0

#include <ostream>
#include <string>

#include "../../DataTypes/header/DtFecha.h"
#include "Arribo.h"

class Puerto
{
    private:
        std::string id;
        std::string nombre;
        DtFecha fechaCreacion;

        //Pseudo atributos
        Arribo arribos[MAX_ARRIBO];
        int cantArribos;

    public:
        Puerto();
        Puerto(std::string, std::string, DtFecha);
        ~Puerto();

        void setId(std::string);
        std::string getId();
        
        void setNombre(std::string);
        std::string getNombre();
        
        void setFechaCreacion(DtFecha);
        DtFecha getFechaCreacion();

        void setCantArribos(int);
        int getCantArribos();

        Arribo* getArribo();
};

#endif