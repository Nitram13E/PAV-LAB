#include "main.h"

Puertos arr = new str_Puertos;

void agregarPuerto(std::string id, std::string nombre, DtFecha fechaCreacion){
  //if(/*Si ya existe un puerto con el ID */){
  /*  throw std::invalid_argument("Ya existe el puerto.");
  }*/
  Puerto* p = new Puerto(id,nombre,fechaCreacion);
  arr -> puerto[arr ->cantPuertos] = p;
  arr -> cantPuertos++;
}

DtPuerto** listarPuerto(int& cantPuertos){
    cantPuertos = arr->cantPuertos;
    DtPuerto** arreglo = new DtPuerto*[cantPuertos];
    for(int i=0; i<cantPuertos; i++){
        DtPuerto *auxP = new DtPuerto(arr -> puerto[i] -> getId(), arr -> puerto[i] -> getNombre(), arr -> puerto[i] -> getFechaCreacion(), arr -> puerto[i] -> getCantArribos());
        arreglo[i] = auxP;
    }

    return arreglo;
}

int main()
{
    BarcoPasajero * pas = new BarcoPasajero();

    BarcoPesquero * pesq = new BarcoPesquero();
    

    return 0;
}