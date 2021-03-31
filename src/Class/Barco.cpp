#include "header/Barco.h"

Barco::Barco(){}

Barco::Barco(std::string id, std::string nombre)
{
    this -> id = id;
    this -> nombre = nombre;
}

Barco::~Barco()
{
}

void Barco::setId(std::string id)
{
    this -> id = id;
}

std::string Barco::getId()
{
    return this -> id;
}

void Barco::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

std::string Barco::getNombre()
{
    return this -> nombre;
}