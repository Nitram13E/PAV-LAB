#include "header/Fecha.h"

Fecha::Fecha(){}

Fecha::Fecha(int dia, int mes, int anio)
{
    if (checkFecha(dia, mes, anio))
    {
        this -> dia = dia;
        this -> mes = mes;
        this -> anio = anio;
    }
    else
    {
        throw std::invalid_argument("Fecha invalida\n");
    }
}

void Fecha::setDia(int dia)
{
    this -> dia = dia;
}

int Fecha::getDia()
{
    return this -> dia;
}

void Fecha::setMes(int mes)
{
    this -> mes = mes;
}

int Fecha::getMes()
{
    return this -> mes;
}

void Fecha::setAnio(int anio)
{
    this -> anio = anio;
}

int Fecha::getAnio()
{
    return this -> anio;
}

Fecha::~Fecha()
{

}

std::ostream& operator << (std::ostream& salida, Fecha fecha)
{
    std::cout << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << std::endl;

    return salida;
}

bool operator == (Fecha f1, Fecha f2)
{
    return f1.getDia() == f2.getDia() && f1.getMes() == f2.getMes() && f1.getAnio() == f2.getAnio();
}
    
bool operator < (Fecha f1, Fecha f2)
{
    if (f1.getAnio() > f2.getAnio()) return false;

    if((f1.getAnio() == f2.getAnio()) && (f1.getMes() > f2.getMes())) return false;

    if((f1.getAnio() == f2.getAnio()) && (f1.getMes() == f2.getMes()) && (f1.getDia() > f2.getDia())) return false;

    return true;
}

bool Fecha::checkFecha(int dia, int mes, int anio)
{
    if ((1 <= dia <= 31) && (1 <= mes <= 12) && (anio >= 1900)) return true;
    
    return false;
}