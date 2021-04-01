#include "Class/header/Arribo.h"
#include "Class/header/Barco.h"
#include "Class/header/Puerto.h"
#include "Class/header/Barcos/BarcoPasajero.h"
#include "Class/header/Barcos/BarcoPesquero.h"

#include "DataTypes/header/Barcos/DtBarcoPasajero.h"
#include "DataTypes/header/Barcos/DtBarcoPesquero.h"
#include "DataTypes/header/DtArribo.h"
#include "DataTypes/header/DtBarco.h"
#include "DataTypes/header/DtFecha.h"
#include "DataTypes/header/DtPuerto.h"
#include "DataTypes/header/TipoTamanio.h"

#define MAX_BARCOS 50
#define MAX_PUERTOS 50

typedef struct str_Puertos
{
    Puerto *puerto[MAX_PUERTOS];
    int cantPuertos;
}*Puertos;

typedef struct str_Barcos
{
    Barco *barcos[MAX_BARCOS];
    int cantBarcos;    
}*Barcos;