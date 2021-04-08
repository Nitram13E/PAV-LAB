
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

void BarcoPesquero::arribar(float cargaDespacho)
{
    if (this -> getCarga() >= (int)cargaDespacho)
    {
        this -> setCarga(this -> getCarga() - (int)cargaDespacho);
    }
    else
    {
        throw std::invalid_argument("No hay carga suficiente para retirar.");
    }
}

void BarcoPesquero::partir(float cargaDespacho)
{
    if ((this -> getCarga() - (int)cargaDespacho) <= this -> getCapacidad())
    {
        this -> setCarga(this -> getCarga() - (int)cargaDespacho);
    }
    else
    {
        throw std::invalid_argument("Carga excedida.");
    }
}

DtBarco* BarcoPesquero::getDtBarco()
{
    DtBarcoPesquero* dtpes = new DtBarcoPesquero(this -> getId(), this -> getNombre(), this -> getCapacidad(), this -> getCarga());

    return dtpes;
}