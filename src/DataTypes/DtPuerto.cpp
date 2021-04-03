#include "header/DtPuerto.h"

DtPuerto::DtPuerto(){}
        
DtPuerto::DtPuerto(std::string id, std::string nombre, DtFecha fechaCreacion, int cantArribos)
{
    this -> id = id;
    this -> nombre = nombre;
    this -> fechaCreacion = fechaCreacion;
    this -> cantArribos = cantArribos;
}

DtPuerto::~DtPuerto()
{
    
}

void DtPuerto::setId(std::string id)
{
    this -> id = id;
}

std::string DtPuerto::getId()
{
    return this -> id;    
}


void DtPuerto::setNombre(std::string nombre)
{
    this -> nombre = nombre;
}

std::string DtPuerto::getNombre()
{
    return this -> nombre;
}

void DtPuerto::setFechaCreacion(DtFecha)
{
    this -> fechaCreacion = fechaCreacion;
}

DtFecha DtPuerto::getFechaCreacion()
{
    return this -> fechaCreacion;
}

void DtPuerto::setCantArribos(int cant)
{
    this -> cantArribos = cant;
}

int DtPuerto::getCantArribos()
{
    return this -> cantArribos;
}

std::ostream& operator << (std::ostream& salida, DtPuerto p)   
{
    std::cout << " - Id Puerto: " << p.getId() << std::endl;
    std::cout << " - Nombre: " << p.getNombre() << std::endl;
    std::cout << " - Fecha de Creacion: " << p.getFechaCreacion() << std::endl;
    std::cout << " - Cantidad de Arribos: " << p.getCantArribos() << std::endl;

    return salida;
}