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

std::ostream& operator << (std::ostream& salida, DtBarcoPesquero pesquero)
{
    std::cout << (DtBarco) pesquero;

    std::cout << "- Tipo de barco: Barco pesquero" << std::endl;

    std::cout << "- Capacidad: " << pesquero.getCapacidad() << std::endl;

    std::cout << "- Carga: " << pesquero.getCarga() << std::endl;

    return salida;
}
