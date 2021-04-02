#ifndef COLBARCO

#define COLBARCO
#define MAX_BARCOS 50

#include "../../DataTypes/header/DtBarco.h"

typedef struct DtBarcos
{
    DtBarco * barcos[MAX_BARCOS];
    int cantBarcos;    

}*colBarcos;

void agregarBarco(DtBarco& barco);

#endif