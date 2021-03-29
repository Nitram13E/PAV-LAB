#include "header/Puerto.h"


DtPuerto::DtPuerto(){}
        
DtPuerto::DtPuerto(std::string id, std::string nombre, DtFecha fechaCreacion)
{
    this -> id = id;
    this -> nombre = nombre;
    this -> fechaCreacion = fechaCreacion;
    this -> cantArribos = CANT_ARRIBOS;

    this -> arribos = new DtArribo[MAX_ARRIBO];
}

DtPuerto::~DtPuerto()
{
    
}

void DtPuerto::setId(std::string id)
{
    this -> id = id;
}

std::string DtPuerto::getId()
{
    return this -> id;    
}


void DtPuerto::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

std::string DtPuerto::getNombre()
{
    return this -> nombre;
}

void DtPuerto::setFechaCreacion(DtFecha)
{
    this -> fechaCreacion = fechaCreacion;
}

DtFecha DtPuerto::getFechaCreacion()
{
    return this -> fechaCreacion;
}
