#ifndef COLSTRUCT
#define COLSTRUCT

#include "../../Class/header/Puerto.h"
#include "../../Class/header/Barco.h"
#include "../../Class/header/Barcos/BarcoPesquero.h"

#define MAX_BARCOS 50
#define MAX_PUERTOS 50

struct Barcos
{
    Barco * barcos[MAX_BARCOS];
    int cantBarcos;    

}barcos;

struct Puertos
{
    Puerto * puertos[MAX_PUERTOS];
    int cantPuertos;

}puertos;

#endif