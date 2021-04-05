#include "header/Arribo.h"

Arribo::Arribo()
{
}

Arribo::Arribo(DtFecha fecha, float carga, Barco* barco)
{
    this -> fecha = fecha;
    this -> carga = carga;
    this -> barco = barco;
}

void Arribo::setFecha(DtFecha fecha)
{
    this -> fecha = fecha;
}

DtFecha Arribo::getFecha()
{
    return this -> fecha;
}

void Arribo::setCarga(float carga)
{
    this -> carga = carga;
}

float Arribo::getCarga()
{
    return this -> carga;
}

void Arribo::setBarco(Barco *barco)
{
    this -> barco = barco;
}

Barco* Arribo::getBarco()
{
    return this -> barco;
}

Arribo::~Arribo()
{
}