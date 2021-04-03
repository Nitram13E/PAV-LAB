#include "header/ColBarco.h"
#include "../../DataTypes/header/Barcos/DtBarcoPesquero.h"
#include "../../DataTypes/header/Barcos/DtBarcoPasajero.h"
#include "../../Class/header/Barcos/BarcoPesquero.h"
#include "../../Class/header/Barcos/BarcoPasajero.h"

//MOVER A MENU/MAIN CUANDO SEA IMPLEMENTADO
barcos col = new struct barcos;

void agregarBarco(DtBarco& barco)
{
    for (int i = 0; i < col -> cantBarcos; i++)
    {
        if (barco.getId() == col -> barcos[i] -> getId())
        {
            throw std::invalid_argument("El barco ya existe en el sistema.");
        }
    }

    col -> barcos[col -> cantBarcos] = convertirBarco(barco); //Necesario verificar array no completo
    col -> cantBarcos++;
}

Barco * convertirBarco(DtBarco& barco)
{
    try
    {
        DtBarcoPesquero& dt = dynamic_cast<DtBarcoPesquero&>(barco);
        BarcoPesquero * newBarco = new BarcoPesquero(dt.getId(), dt.getNombre(), dt.getCapacidad(), dt. getCarga());

        return newBarco;
    }
    catch(std::bad_cast)
    {
        DtBarcoPasajero& dt = dynamic_cast<DtBarcoPasajero&>(barco);
        BarcoPasajero * newBarco = new BarcoPasajero(dt.getId(), dt.getNombre(), dt.getCantPasajeros(), dt.getTamanio());

        return newBarco;
    }
    catch(std::bad_cast){}
}
