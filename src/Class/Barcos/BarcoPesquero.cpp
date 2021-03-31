#include "../header/Barcos/BarcoPesquero.h"

BarcoPesquero::BarcoPesquero(){}

BarcoPesquero::BarcoPesquero(std::string id, std::string nombre, int capacidad, int carga)
{
    this -> setId(id);
    this -> setNombre(nombre);
    this -> capacidad = capacidad;
    this -> carga = carga;   
}

void BarcoPesquero::setCapacidad(int capacidad)
{
    this -> capacidad = capacidad;
}

int BarcoPesquero::getCapacidad()
{
    return this -> capacidad;
}

void BarcoPesquero::setCarga(int carga)
{
    this -> carga = carga;
}

int BarcoPesquero::getCarga()
{
    return this -> carga;
}

void BarcoPesquero::arribar(float)
{
    
}