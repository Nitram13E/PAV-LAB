#ifndef COLARRIBO
#define COLARRIBO

#include "../../Class/header/Puerto.h"
#include "../../Class/header/Barco.h"
#include "../../Class/header/Barcos/BarcoPesquero.h"

#define MAX_BARCOS 50
#define MAX_PUERTOS 50

typedef struct str_Puertos
{
    Puerto *puertos[MAX_PUERTOS];
    int cantPuertos;
}*Puertos;

typedef struct str_Barcos
{
    Barco *barcos[MAX_BARCOS];
    int cantBarcos;    
}*Barcos;

void agregarArribo(std::string idPuerto, std::string idBarco, DtFecha fecha, float cargaDespacho);

Puerto* existePuerto(std::string idPuerto);

Barco* existeBarco(std::string idBarco);

void efectuarCarga(Barco* barco, float cargaDespacho);

#endif