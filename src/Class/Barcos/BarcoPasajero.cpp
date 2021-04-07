#include "../header/Barcos/BarcoPasajero.h"

BarcoPasajero::BarcoPasajero(){}

BarcoPasajero::BarcoPasajero(std::string id, std::string nombre, int cantPasajeros, TipoTamanio tamanio) 
{
    this -> setId(id);
    this -> setNombre(nombre);
    this -> cantPasajeros = cantPasajeros;
    this -> tamanio = tamanio;
}

void BarcoPasajero::setCantPasajeros(int cantPasajeros)
{
    this -> cantPasajeros = cantPasajeros;
}

int BarcoPasajero::getCantPasajeros()
{
    return this -> cantPasajeros;
}

void BarcoPasajero::setTamanio(TipoTamanio tamanio)
{
    this -> tamanio = tamanio;
}

TipoTamanio BarcoPasajero::getTamanio()
{
    return this -> tamanio;
}

void BarcoPasajero::arribar(float cargaDespacho) {}

DtBarco* BarcoPasajero::getDtBarco()
{
    DtBarcoPasajero* dtpas = new DtBarcoPasajero(this -> getId(), this -> getNombre(), this -> getCantPasajeros(), this -> getTamanio());

    return dtpas;
}

