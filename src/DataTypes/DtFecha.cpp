#include "header/DtFecha.h"

DtFecha::DtFecha(){}

DtFecha::DtFecha(int dia, int mes, int anio)
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

void DtFecha::setDia(int dia)
{
    this -> dia = dia;
}

int DtFecha::getDia()
{
    return this -> dia;
}

void DtFecha::setMes(int mes)
{
    this -> mes = mes;
}

int DtFecha::getMes()
{
    return this -> mes;
}

void DtFecha::setAnio(int anio)
{
    this -> anio = anio;
}

int DtFecha::getAnio()
{
    return this -> anio;
}

DtFecha::~DtFecha()
{

}

std::ostream& operator << (std::ostream& salida, DtFecha fecha)
{
    std::cout << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << std::endl;

    return salida;
}

bool operator == (DtFecha f1, DtFecha f2)
{
    return f1.getDia() == f2.getDia() && f1.getMes() == f2.getMes() && f1.getAnio() == f2.getAnio();
}
    
bool operator < (DtFecha f1, DtFecha f2)
{
    if (f1.getAnio() > f2.getAnio()) return false;

    if((f1.getAnio() == f2.getAnio()) && (f1.getMes() > f2.getMes())) return false;

    if((f1.getAnio() == f2.getAnio()) && (f1.getMes() == f2.getMes()) && (f1.getDia() > f2.getDia())) return false;

    return true;
}

bool DtFecha::checkFecha(int dia, int mes, int anio)
{
    if ((1 <= dia <= 31) && (1 <= mes <= 12) && (anio >= 1900)) return true;
    
    return false;
}