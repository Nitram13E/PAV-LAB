#include "../header/Barcos/DtBarcoPasajero.h"

DtBarcoPasajero::DtBarcoPasajero(){}

DtBarcoPasajero::DtBarcoPasajero(std::string id, std::string nombre, int cantPasajeros, TipoTamanio tamanio) 
{
    this -> setId(id);
    this -> setNombre(nombre);
    this -> cantPasajeros = cantPasajeros;
    this -> tamanio = tamanio;
}

void DtBarcoPasajero::setCantPasajeros(int cantPasajeros)
{
    this -> cantPasajeros = cantPasajeros;
}

int DtBarcoPasajero::getCantPasajeros()
{
    return this -> cantPasajeros;
}

void DtBarcoPasajero::setTamanio(TipoTamanio tamanio)
{
    this -> tamanio = tamanio;
}

TipoTamanio DtBarcoPasajero::getTamanio()
{
    return this -> tamanio;
}