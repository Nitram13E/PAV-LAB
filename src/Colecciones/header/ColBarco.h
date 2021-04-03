#ifndef COLBARCO
#define COLBARCO
#define MAX_BARCOS 50

#include "Structs.h"
#include "../../DataTypes/header/DtBarco.h"

void agregarBarco(DtBarco& barco);

DtBarco** listarBarcos(int& cantBarcos);

#endif