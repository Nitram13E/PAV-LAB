#include "header/DtBarco.h"

DtBarco::DtBarco(){}

DtBarco::DtBarco(std::string id, std::string nombre)
{
    this -> id = id;
    this -> nombre = nombre;
}

DtBarco::~DtBarco()
{
}

void DtBarco::setId(std::string id)
{
    this -> id = id;
}

std::string DtBarco::getId()
{
    return this -> id;
}

void DtBarco::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

std::string DtBarco::getNombre()
{
    return this -> nombre;
}

std::ostream& operator << (std::ostream& salida, DtBarco barco)
{
    std::cout << "- IdBarco: " << barco.getId() << std::endl;
    std::cout << "- Nombre: " << barco.getNombre() << std::endl;

    return salida;
}