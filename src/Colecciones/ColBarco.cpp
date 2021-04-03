#include "header/ColBarco.h"
#include "../../DataTypes/header/Barcos/DtBarcoPesquero.h"
#include "../../DataTypes/header/Barcos/DtBarcoPasajero.h"
#include "../../Class/header/Barcos/BarcoPesquero.h"
#include "../../Class/header/Barcos/BarcoPasajero.h"

void agregarBarco(DtBarco& barco)
{
    for (int i = 0; i < barcos.cantBarcos; i++)
    {
        if (barco.getId() == barcos.barcos[i] -> getId())
        {
            throw std::invalid_argument("El barco ya existe en el sistema.");
        }
    }

    barcos.barcos[barcos.cantBarcos] = convertirBarco(barco); //Necesario verificar array no completo
    barcos.cantBarcos++;
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

DtBarco** listarBarcos(int& cantBarcos)
{
    DtBarco** dtbarcos = new DtBarco*[barcos.cantBarcos];

    DtBarcoPesquero* dtpes;

    DtBarcoPasajero* dtpas;

    cantBarcos = barcos.cantBarcos;

    for (int i = 0; i < cantBarcos; i++)
    {
        if (BarcoPesquero* pes = dynamic_cast<BarcoPesquero*>(barcos.barcos[i]))
        {
            dtpes = new DtBarcoPesquero(pes -> getId(), pes -> getNombre(), pes -> getCapacidad(), pes -> getCarga());

            dtbarcos[i] = dtpes;

        }
        else
        {
            if (BarcoPasajero* pas = dynamic_cast<BarcoPasajero*>(barcos.barcos[i]))
            {
                dtpas = new DtBarcoPasajero(pas -> getId(), pas -> getNombre(), pas -> getCantPasajeros(), pas -> getTamanio());

                dtbarcos[i] = dtpas;
            }
        }
    }
    
    return dtbarcos;
}
