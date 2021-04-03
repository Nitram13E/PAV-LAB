#include "header/ColPuertos.h"
#include "header/ColArribo.h"
#include "../../DataTypes/header/DtBarco.h"
#include "../../DataTypes/header/DtPuerto.h"
#include "../../DataTypes/header/Barcos/DtBarcoPasajero.h"
#include "../../DataTypes/header/Barcos/DtBarcoPesquero.h"
#include "../../Class/header/Barcos/BarcoPasajero.h"


void agregarPuerto(std::string id, std::string nombre, DtFecha fechaCreacion)
{
    if(existePuerto(id) != NULL)
    {
        throw std::invalid_argument("Ya existe el puerto con idPuerto: " + id);
        return;
    }
  
    Puerto* p = new Puerto(id,nombre,fechaCreacion);

    puertos.puertos[puertos.cantPuertos] = p;

    puertos.cantPuertos++;
}

DtPuerto** listarPuerto(int& cantPuertos)
{
    cantPuertos = puertos.cantPuertos;

    DtPuerto** arreglo = new DtPuerto*[cantPuertos];

    for(int i = 0; i < cantPuertos; i++)
    {
        DtPuerto *auxP = new DtPuerto(puertos.puertos[i] -> getId(), puertos.puertos[i] -> getNombre(), puertos.puertos[i] -> getFechaCreacion(), puertos.puertos[i] -> getCantArribos());

        arreglo[i] = auxP;
    }

    return arreglo;
}

DtArribo** obtenerInfoArribosEnPuerto(std::string idPuerto, int& cantArribos)
{
    Puerto * puerto = existePuerto(idPuerto);
    int length;
    
    if (puerto == NULL)
    {
        throw std::invalid_argument("NO EXISTE UN PUERTO CON EL ID: " + idPuerto);
        return NULL;
    }

    if(cantArribos <= puerto -> getCantArribos())
        length = cantArribos;
    else
        length = puerto -> getCantArribos();
    //En caso de que cantArribos sea mayor a la cantidad de arribos del puerto, se devueleve todos los arribos del puerto

    DtArribo ** arrayArribo = copiarArrayArribo(puerto -> getArribos(), length);
    
    return arrayArribo;
}

DtArribo ** copiarArrayArribo(Arribo * original, int cantArribos)
{
    DtArribo ** copia = new DtArribo*[cantArribos];

    for (int i = 0; i < cantArribos; i++)
    {
        copia[i] -> setFecha(original[i].getFecha());
        copia[i] -> setCarga(original[i].getCarga());

        BarcoPesquero* barco_pesquero = dynamic_cast<BarcoPesquero*>(original[i].getBarco());
        BarcoPasajero* barco_pasajero = dynamic_cast<BarcoPasajero*>(original[i].getBarco());


        DtBarcoPasajero * copiaBarcoPasajero;
        DtBarcoPesquero * copiaBarcoPesquero;

        if (barco_pasajero != NULL)
        {  
            copiaBarcoPasajero = new DtBarcoPasajero();
            copiaBarcoPasajero -> setId(barco_pasajero -> getId());
            copiaBarcoPasajero -> setNombre(barco_pasajero -> getNombre());
            copiaBarcoPasajero -> setCantPasajeros(barco_pasajero -> getCantPasajeros());
            copiaBarcoPasajero -> setTamanio(barco_pasajero -> getTamanio());
            copia[i] -> setBarco(copiaBarcoPasajero);
        }
        else
        {
            copiaBarcoPesquero = new DtBarcoPesquero();
            copiaBarcoPesquero -> setId(barco_pesquero -> getId());
            copiaBarcoPesquero -> setNombre(barco_pesquero -> getNombre());
            copiaBarcoPesquero -> setCapacidad(barco_pesquero -> getCapacidad());
            copiaBarcoPesquero -> setCarga(barco_pesquero -> getCarga());
            copia[i] -> setBarco(copiaBarcoPasajero);
        }

    }
    return copia;
}

void eliminarArribos(std::string idPuerto, DtFecha fecha)
{
    Puerto * puerto = existePuerto(idPuerto);
    Arribo * arrayArribo;
    
    if (puerto == NULL)
    {
        throw std::invalid_argument("NO EXISTE UN PUERTO CON EL ID: " + idPuerto);
        return;
    }

    arrayArribo = puerto -> getArribos();
    
    for (int i = 0; i < puerto -> getCantArribos(); i++)
    {
        if (arrayArribo[i].getFecha() == fecha)
        {
            for (int j = i; j < puerto -> getCantArribos() - 1; j++)
            {
                arrayArribo[j] = arrayArribo[j + 1];
            }
        }
    }

    puerto -> setCantArribos(puerto -> getCantArribos() - 1);
}