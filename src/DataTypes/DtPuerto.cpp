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

std::string DtPuerto::getId()
{
    return this -> id;    
}

std::string DtPuerto::getNombre()
{
    return this -> nombre;
}

DtFecha DtPuerto::getFechaCreacion()
{
    return this -> fechaCreacion;
}

int DtPuerto::getCantArribos()
{
    return this -> cantArribos;
}

std::ostream& operator << (std::ostream& salida, DtPuerto p)   
{
    std::cout << " - Id Puerto: " << p.getId() << std::endl;
    std::cout << " - Nombre: " << p.getNombre() << std::endl;
    std::cout << " - Fecha de Creacion: " << p.getFechaCreacion();
    std::cout << " - Cantidad de Arribos: " << p.getCantArribos() << std::endl;

    return salida;
} 