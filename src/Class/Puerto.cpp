#include "header/Puerto.h"

Puerto::Puerto(){}
        
Puerto::Puerto(std::string id, std::string nombre, DtFecha fechaCreacion)
{
    this -> id = id;
    this -> nombre = nombre;
    this -> fechaCreacion = fechaCreacion;
    this -> cantArribos = CANT_ARRIBOS;
}

Puerto::~Puerto()
{
    
}

void Puerto::setId(std::string id)
{
    this -> id = id;
}

std::string Puerto::getId()
{
    return this -> id;    
}


void Puerto::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

std::string Puerto::getNombre()
{
    return this -> nombre;
}

void Puerto::setFechaCreacion(DtFecha fechaCreacion)
{
    this -> fechaCreacion = fechaCreacion;
}

DtFecha Puerto::getFechaCreacion()
{
    return this -> fechaCreacion;
}

void Puerto::setCantArribos(int cant)
{
    this -> cantArribos = cant;
}

int Puerto::getCantArribos()
{
    return this -> cantArribos;
}

Arribo** Puerto:: getArribos()
{
    return this -> arribos;
}

void Puerto::agregarArribos(Arribo* arribo)
{
    this -> arribos[this -> cantArribos] = arribo;

    this -> cantArribos++;
}

DtArribo** Puerto::getDtArribos()
{
    DtArribo ** arribo = new DtArribo*[this -> cantArribos];

    for (int i = 0; i < this -> cantArribos; i++)
    {
        arribo[i] = new DtArribo(this -> arribos[i] -> getFecha(), this -> arribos[i] -> getCarga(), this -> arribos[i] -> getDtBarco());
    }

    return arribo;
}
