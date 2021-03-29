#include "../header/Barcos/BarcoPasajero.h"

DtBarcoPasajero::DtBarcoPasajero(){}

DtBarcoPasajero::DtBarcoPasajero(std::string id, std::string nombre, int cantPasajeros, TipoTamanio tamanio) 
{
    this -> setId(id);
    this -> setNombre(nombre);
    this -> cantPasajeros = cantPasajeros;
    this -> tamanio = tamanio;
}

void DtBarcoPasajero::setCantPasajeros(int cantPasajeros)
{
    this -> cantPasajeros = cantPasajeros;
}

int DtBarcoPasajero::getCantPasajeros()
{
    return this -> cantPasajeros;
}

void DtBarcoPasajero::setTamanio(TipoTamanio tamanio)
{
    this -> tamanio = tamanio;
}

TipoTamanio DtBarcoPasajero::getTamanio()
{
    return this -> tamanio;
}

void DtBarcoPasajero::arribar(float cargaDespacho)
{
    
}

// ostream& operator <<(ostream& salida,DtTerrestre& terrestre){
//   cout << (DtLugar) terrestre << " Pais: " << terrestre.pais << endl;
//   return salida;
// }

// ostream& operator << (ostream& salida, const DtLugar& lugar){
//   string g[7]={"ALMA","ESPACIO","MENTE","REALIDAD","TIEMPO","PODER","NINGUNA"};
//   cout << "Nombre: " << lugar.nombre << " Gema: " << g[lugar.gema] << " Dificultad: " << lugar.dificultad << endl;
//   return salida;
// }