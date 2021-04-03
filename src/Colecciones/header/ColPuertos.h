#ifndef COLPUERTOS
#define COLPUERTOS
#include <iostream>

#include "../../DataTypes/header/DtArribo.h"
#include "ColStructs.h"

DtArribo** obtenerInfoArribosEnPuerto(std::string idPuerto, int& cantArribos);

void eliminarArribos(std::string idPuerto, DtFecha fecha);

#endif