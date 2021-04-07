#include "../header/Barcos/DtBarcoPasajero.h"

DtBarcoPasajero::DtBarcoPasajero(){}

DtBarcoPasajero::DtBarcoPasajero(std::string id, std::string nombre, int cantPasajeros, TipoTamanio tamanio) : DtBarco(id, nombre) 
{
    this -> cantPasajeros = cantPasajeros;
    this -> tamanio = tamanio;
}

int DtBarcoPasajero::getCantPasajeros()
{
    return this -> cantPasajeros;
}

TipoTamanio DtBarcoPasajero::getTamanio()
{
    return this -> tamanio;
}

std::ostream& operator << (std::ostream& salida, DtBarcoPasajero pasajero)
{
    std::cout << (DtBarco) pasajero;

    std::cout << "- Tipo de barco: Barco pasajero" << std::endl;

    std::cout << "- Cantidad de pasajeros: " << pasajero.getCantPasajeros() << std::endl;

    std:: cout << "- Tamanio: " << pasajero.getTamanio() << std::endl;

    return salida;
}