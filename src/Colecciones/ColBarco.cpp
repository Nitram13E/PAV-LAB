#include "header/ColBarco.h"
#include "../../DataTypes/header/Barcos/BarcoPesquero.h"
#include "../../DataTypes/header/Barcos/BarcoPasajero.h"
#include "../../Class/header/Barcos/BarcoPesquero.h"
#include "../../Class/header/Barcos/BarcoPasajero.h"

void agregarBarco(DtBarco& barco)
{
    Barco newBarco = 
    DtBarcoPesquero& dtPesquero = dynamic_cast<DtBarcoPesquero&>(barco);
 
    
    
    if(dtPesquero != NULL) //Tipo pesquero
    {
        BarcoPesquero * newPesquero = new BarcoPesquero(dtPesquero -> getId(), dtPesquero -> getNombre(), dtPesquero -> getCapacidad(), dtPesquero -> getCarga());
    }
    else//Tipo pasajero
    {
        BarcoPasajero * newPasajero = new BarcoPasajero(dtPasajero -> getId(), dtPasajero -> getNombre(), dtPasajero -> getCantPasajeros(), dtPasajero -> getTamanio());

        Barco& newBarco = dynamic_cast<Barco&>(newPasajero*);
    }
}

