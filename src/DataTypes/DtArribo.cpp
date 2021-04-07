#include "header/DtArribo.h"

DtArribo::DtArribo()
{
}

DtArribo::DtArribo(DtFecha fecha, float carga, DtBarco* barco)
{
    this -> fecha = fecha;
    this -> carga = carga;
    this -> barco = barco;
}

DtFecha DtArribo::getFecha()
{
    return this -> fecha;
}

float DtArribo::getCarga()
{
    return this -> carga ;
}

DtBarco* DtArribo::getBarco()
{
    return this -> barco;
}

DtArribo::~DtArribo()
{
}

std::ostream& operator << (std::ostream& salida, DtArribo arr)
{
    std::cout << arr.getFecha();
    std::cout << "- Carga: " << arr.getCarga() << std::endl;
    
    DtBarcoPasajero* dtpas = dynamic_cast<DtBarcoPasajero*>(arr.getBarco());

    if(dtpas != NULL)
    {
        std::cout << *dtpas;
    } 
    else
    {
        DtBarcoPesquero* dtpes = dynamic_cast<DtBarcoPesquero*>(arr.getBarco());

        std::cout << *dtpes;
    } 

    return salida;
}