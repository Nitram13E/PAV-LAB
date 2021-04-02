#ifndef COLARRIBO
#define COLARRIBO

#include "ColStructs.h"

void agregarArribo(std::string idPuerto, std::string idBarco, DtFecha fecha, float cargaDespacho);

Puerto* existePuerto(std::string idPuerto);

Barco* existeBarco(std::string idBarco);

void efectuarCarga(Barco* barco, float cargaDespacho);

#endif