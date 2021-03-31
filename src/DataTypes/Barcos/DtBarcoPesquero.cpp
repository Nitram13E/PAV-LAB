#include "../header/Barcos/DtBarcoPesquero.h"

DtBarcoPesquero::DtBarcoPesquero(){}

DtBarcoPesquero::DtBarcoPesquero(std::string id, std::string nombre, int capacidad, int carga)
{
    this -> setId(id);
    this -> setNombre(nombre);
    this -> capacidad = capacidad;
    this -> carga = carga;   
}

void DtBarcoPesquero::setCapacidad(int capacidad)
{
    this -> capacidad = capacidad;
}

int DtBarcoPesquero::getCapacidad()
{
    return this -> capacidad;
}

void DtBarcoPesquero::setCarga(int carga)
{
    this -> carga = carga;
}

int DtBarcoPesquero::getCarga()
{
    return this -> carga;
}

void DtBarcoPesquero::arribar(float)
{
    
}