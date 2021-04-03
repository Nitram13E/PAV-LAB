#include "header/ColArribo.h"

void agregarArribo(std::string idPuerto, std::string idBarco, DtFecha fecha, float cargaDespacho)
{
    Puerto* puerto = existePuerto(idPuerto);

    Barco* barco = existeBarco(idBarco);
    
    if (puerto == NULL || barco == NULL)//Excepecion si no existe barco o no existe puerto
    {
        throw std::invalid_argument("No se pudo agregar un arribo.");
    }

    efectuarCarga(barco, cargaDespacho);
    
    Arribo * arribo = new Arribo(fecha, cargaDespacho, barco);

    puerto -> getArribo()[puerto -> getCantArribos() - 1] = *arribo;

    puerto -> setCantArribos(puerto -> getCantArribos() + 1);
}

Puerto* existePuerto(std::string idPuerto)
{
    puertos iterador;

    for (int i = 0; i < iterador -> cantPuertos; i++)
    {
        if (iterador -> puertos[i] -> getId() == idPuerto)
        {
            return iterador -> puertos[i];
        }
    }

    return NULL;
}

Barco* existeBarco(std::string idBarco)
{
    barcos iterador;
    
    for (int i = 0; i < iterador -> cantBarcos; i++)
    {
        if (iterador -> barcos[i] -> getId() == idBarco)
        {
            return iterador -> barcos[i];
        }
    }

    return NULL;
}

void efectuarCarga(Barco* barco, float cargaDespacho)
{
    BarcoPesquero* pesq = dynamic_cast<BarcoPesquero*>(barco);

    if (pesq == NULL) return;

    if (cargaDespacho > 0)
    {
        pesq -> arribar(cargaDespacho);
    }
    else //Si el valor de carga que se despacha es negativo o 0
    {   
        pesq -> partir(-cargaDespacho);
    }
}
