#include <iostream>
#include <unistd.h>
#include "Class/header/Barco.h"
#include "Class/header/Puerto.h"

#include "DataTypes/header/DtBarco.h"
#include "Class/header/Barcos/BarcoPasajero.h"
#include "Class/header/Barcos/BarcoPesquero.h"
#include "DataTypes/header/Barcos/DtBarcoPasajero.h"
#include "DataTypes/header/Barcos/DtBarcoPesquero.h"
#include "DataTypes/header/DtPuerto.h"
#include "DataTypes/header/DtArribo.h"


#define MAX_BARCOS 50
#define MAX_PUERTOS 50

struct Barcos
{
    Barco * bar[MAX_BARCOS];
    int cantBarcos;

}barcos;

struct Puertos
{
    Puerto * puert[MAX_PUERTOS];
    int cantPuertos;

}puertos;

/////////////////////////////////////////////////////////////////////

Puerto* existePuerto(std::string idPuerto);

Barco* existeBarco(std::string idBarco);

void efectuarCarga(Barco* barco, float cargaDespacho);

void agregarArribo(std::string idPuerto, std::string idBarco, DtFecha fecha, float cargaDespacho);


Barco * convertirBarco(DtBarco& barco);

DtBarco** listarBarcos(int& cantBarcos);

void agregarBarco(DtBarco& barco);

DtPuerto** listarPuerto(int& cantPuertos);


DtArribo** obtenerInfoArribosEnPuerto(std::string idPuerto, int& cantArribos);

void eliminarArribos(std::string idPuerto, DtFecha fecha);

DtArribo ** copiarArrayArribo(Arribo * original, int cantArribos);

void agregarPuerto(std::string id, std::string nombre, DtFecha fechaCreacion);



void menu()
{
    int opcion;
    
    do
    {
        system("clear");
        std::cout << "Bienvenido! " << std::endl;
        std::cout << "1) Agregar puerto " << std::endl;
        std::cout << "2) Agregar barco " << std::endl;
        std::cout << "3) Listar puerto " << std::endl;
        std::cout << "4) Agregar arribo " << std::endl;
        std::cout << "5) Obtener informacion de arribos en puerto " << std::endl;
        std::cout << "6) Eliminar arribos " << std::endl;
        std::cout << "7) Listar barcos " << std::endl;
        std::cout << "8) Salir " << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
            case 1://AgregarPuerto
                {
                    system("clear");

                    std::string idPuerto, nombre;
                    int dia, mes, anio;
                    DtFecha * fecha;

                    system("clear");

                    std::cout << "AGREGAR PUERTO" << std::endl << std::endl;

                    std::cout << "- Ingrese idPuerto: ";
                    std::cin >> idPuerto;

                    std::cout << "- Ingrese Nombre: ";
                    std::cin >> nombre;

                    std::cout << "- Ingrese una fecha: " << std::endl;

                    std::cout << "dia: ";
                    std::cin >> dia;
                    
                    std::cout << "mes: ";
                    std::cin >> mes;

                    std::cout << "anio: ";
                    std::cin >> anio;

                    fecha = new DtFecha(dia, mes, anio);

                    try
                    {
                        agregarPuerto(idPuerto, nombre, *fecha);
                    }
                    catch(std::invalid_argument& error)
                    {
                        std::cout << error.what() << std::endl;
                    }
                }
                
                break;
            
            case 2://Agregar Barco
                {   
                    system("clear");
                    
                    int opB;
                    std::string idBarco;
                    std::string nombreBarco;

                    std::cout << "Elija tipo de barco: " << std::endl << std::endl;
                    std::cout << "1 - BarcoPesquero " << std::endl;
                    std::cout << "2 - BarcoPasajero " << std:: endl;
                    std::cout << "Opcion: ";
                    std::cin >> opB;
                    
                    if (opB == 1)
                    {
                        system("clear");


                        int capacidad;
                        int carga;
                        
                        std::cout << "Barco Pesquero" << std::endl << std::endl;

                        std::cout << "Ingrese idBarco: ";
                        std::cin >> idBarco;

                        std::cout << "Ingrese nombre: ";
                        std::cin >> nombreBarco;

                        std::cout << "Ingrese capacidad: ";
                        std::cin >> capacidad;

                        std::cout << "Ingrese carga: ";
                        std::cin >> carga;

                        DtBarcoPesquero pesquero = DtBarcoPesquero(idBarco, nombreBarco, capacidad, carga);
                        
                        try
                        {
                            agregarBarco(pesquero);
                        }
                        catch(std::invalid_argument& inv)
                        {
                            std::cout << inv.what() << std::endl;
                        }
                        
                    }
                    else if (opB == 2)
                    {
                        system("clear");

                        int cantPasajeros;
                        int tamanio;

                        std::cout << "Barco Pesquero" << std::endl << std::endl;

                        std::cout << "Ingrese id: ";
                        std::cin >> idBarco;

                        std::cout << "Ingrese nombre: ";
                        std::cin >> nombreBarco;

                        std::cout << "Ingrese cantidad de pasajeros: ";
                        std::cin >> cantPasajeros;

                        std::cout << "Ingrese el tamanio del barco(1: bote, 2: crucero, 3: galeon, 4: transatlantico): ";
                        std::cin >> tamanio;

                        TipoTamanio tipo = static_cast<TipoTamanio>(tamanio);

                        DtBarcoPasajero pasajero = DtBarcoPasajero(idBarco, nombreBarco, cantPasajeros, tipo);
                        
                        try
                        {   
                            agregarBarco(pasajero);
                        }
                        catch(std::invalid_argument& error)
                        {
                            std::cout << error.what() << std::endl;
                        }
                    }
                    
                    break;
                }
                
            case 3: // Listar puerto
                /* code */
                break;

            case 4: //Agregar Arribo
                {
                    system("clear");

                    std::string idPuerto;
                    std::string idBarco;
                    int dia;
                    int mes;
                    int anio;
                    float cargaDespacho;

                    std::cout << "AGREGAR ARRIBO" << std::endl << std::endl;

                    std::cout << "- Ingrese idPuerto: ";
                    std::cin >> idPuerto;

                    std::cout << "- Ingrese idBarco: ";
                    std::cin >> idBarco;

                    std::cout << "- Ingrese una fecha: " << std::endl;

                    std::cout << "dia: ";
                    std::cin >> dia;
                    
                    std::cout << "mes: ";
                    std::cin >> mes;

                    std::cout << "anio: ";
                    std::cin >> anio;

                    std::cout << "- Ingrese carga de despacho: ";
                    std::cin >> cargaDespacho;

                    try
                    {
                        agregarArribo(idPuerto, idBarco, DtFecha(dia, mes, anio), cargaDespacho);
                    }
                    catch(std::invalid_argument& error)
                    {
                        std::cout << error.what() << std::endl;
                    }

                    sleep(6);
                }
                break;
            case 5: //obtenerInfoArribosEnPuerto
                {
                    system("clear");

                    std::string idPuerto;
                    int cantArribos; 
                    DtArribo** arrayArribos;

                    std::cout << "OBTENER INFO ARRIBOS" << std::endl << std::endl;

                    std::cout << "- Ingrese idPuerto: ";
                    std::cin >> idPuerto;

                    std::cout << "- Ingrese cantidad de arribos: ";
                    std::cin >> cantArribos;
                    
                    try
                    {
                        arrayArribos = obtenerInfoArribosEnPuerto(idPuerto, cantArribos);

                        for (int i = 0; i < cantArribos; i++)
                        {
                            std::cout << arrayArribos[i] -> getBarco() << std::endl;
                        }
                    }
                    catch(std::invalid_argument& error)
                    {
                        std::cout << error.what() << std::endl;
                    }

                    sleep(6);
                }
                break;
            case 6: //eliminarArribos
                {
                    system("clear");
                    
                    std::string idPuerto;
                    int dia, mes, anio;
                    DtFecha * fecha;


                    std::cout << "ELIMINAR ARRIBO" << std::endl << std::endl;

                    std::cout << "- Ingrese idPuerto: ";
                    std::cin >> idPuerto;
                    std::cout << "- Ingrese una fecha: " << std::endl;

                    std::cout << "dia: ";
                    std::cin >> dia;
                    
                    std::cout << "mes: ";
                    std::cin >> mes;

                    std::cout << "anio: ";
                    std::cin >> anio;

                    fecha = new DtFecha(dia, mes, anio);
                    
                    try
                    {
                        eliminarArribos(idPuerto, *fecha);
                    }
                    catch(std::invalid_argument& error)
                    {
                        std::cout << error.what() << std::endl;
                    }

                    delete fecha;
                    
                    break;
                }
            case 7: //Listar Barcos
                {
                    system("clear");

                    int barco;

                    DtBarco ** barcolistado = listarBarcos(barco);

                    for (int i = 0; i < barco; i++)
                    {
                        DtBarcoPasajero * pasa = dynamic_cast<DtBarcoPasajero*>(barcolistado[i]);

                        if(pasa == NULL)
                        {
                            DtBarcoPesquero * pesq = dynamic_cast<DtBarcoPesquero*>(barcolistado[i]);

                            std::cout << *pesq << std::endl;
                        }
                        else
                        {
                            std::cout << *pasa << std::endl;
                        }
                    }
                    
                    sleep(6);

                    break;
                }
                
            
            case 8: //Salir
                {
                    system("exit");
                    std::cout << "Saliendo.." << std::endl;

                    break;
                }
            default: //Opcion incorrecta

                std::cout<<"Por favor, introduzca una opcion valida."<<std::endl;

                break;
        }
    }
    while (opcion != 8);
}










int main()
{   
    menu();
    return 0;
}











void agregarArribo(std::string idPuerto, std::string idBarco, DtFecha fecha, float cargaDespacho)
{
    Puerto* puerto = existePuerto(idPuerto);

    Barco* barco = existeBarco(idBarco);
    
    if (puerto == NULL || barco == NULL)//Excepecion si no existe barco o no existe puerto
    {
        throw std::invalid_argument("No se pudo agregar un arribo.");
    }

    efectuarCarga(barco, cargaDespacho);
    
    Arribo * arribo = new Arribo(fecha, cargaDespacho, barco);

    puerto -> getArribos()[puerto -> getCantArribos() - 1] = *arribo;

    puerto -> setCantArribos(puerto -> getCantArribos() + 1);
}

Puerto* existePuerto(std::string idPuerto)
{
    for (int i = 0; i < puertos.cantPuertos; i++)
    {
        if (puertos.puert[i] -> getId() == idPuerto)
        {
            return puertos.puert[i];
        }
    }

    return NULL;
}

Barco* existeBarco(std::string idBarco)
{
    for (int i = 0; i < barcos.cantBarcos; i++)
    {
        if (barcos.bar[i] -> getId() == idBarco)
        {
            return barcos.bar[i];
        }
    }

    return NULL;
}

void efectuarCarga(Barco* barco, float cargaDespacho)
{
    BarcoPesquero* pesq = dynamic_cast<BarcoPesquero*>(barco);

    if (pesq == NULL) return;

    if (cargaDespacho > 0)
    {
        pesq -> arribar(cargaDespacho);
    }
    else //Si el valor de carga que se despacha es negativo o 0
    {   
        pesq -> partir(-cargaDespacho);
    }
}

/////////////////////////////////////////////////////////////////////

void agregarBarco(DtBarco& barco)
{
    for (int i = 0; i < barcos.cantBarcos; i++)
    {
        if (barco.getId() == barcos.bar[i] -> getId())
        {
            throw std::invalid_argument("El barco ya existe en el sistema.");
        }
    }

    barcos.bar[barcos.cantBarcos] = convertirBarco(barco); //Necesario verificar array no completo
    barcos.cantBarcos++;
}

Barco * convertirBarco(DtBarco& barco)
{
    try
    {
        DtBarcoPesquero& dt = dynamic_cast<DtBarcoPesquero&>(barco);
        
        BarcoPesquero * newBarco = new BarcoPesquero(dt.getId(), dt.getNombre(), dt.getCapacidad(), dt. getCarga());

        return newBarco;
    }
    catch(std::bad_cast& e)
    {
        DtBarcoPasajero& dt = dynamic_cast<DtBarcoPasajero&>(barco);

        BarcoPasajero * newBarco = new BarcoPasajero(dt.getId(), dt.getNombre(), dt.getCantPasajeros(), dt.getTamanio());

        return newBarco;
    }

    return NULL;
}

DtBarco** listarBarcos(int& cantBarcos)
{
    DtBarco** dtbarcos = new DtBarco*[barcos.cantBarcos];

    DtBarcoPesquero* dtpes;

    DtBarcoPasajero* dtpas;

    cantBarcos = barcos.cantBarcos;

    for (int i = 0; i < cantBarcos; i++)
    {
        if (BarcoPesquero* pes = dynamic_cast<BarcoPesquero*>(barcos.bar[i]))
        {
            dtpes = new DtBarcoPesquero(pes -> getId(), pes -> getNombre(), pes -> getCapacidad(), pes -> getCarga());

            dtbarcos[i] = dtpes;

        }
        else
        {
            if (BarcoPasajero* pas = dynamic_cast<BarcoPasajero*>(barcos.bar[i]))
            {
                dtpas = new DtBarcoPasajero(pas -> getId(), pas -> getNombre(), pas -> getCantPasajeros(), pas -> getTamanio());

                dtbarcos[i] = dtpas;
            }
        }
    }
    
    return dtbarcos;
}

/////////////////////////////////////////////////////////////////////

void agregarPuerto(std::string id, std::string nombre, DtFecha fechaCreacion)
{
    if(existePuerto(id) != NULL)
    {
        throw std::invalid_argument("Ya existe el puerto con idPuerto: " + id);
        return;
    }
  
    Puerto* p = new Puerto(id,nombre,fechaCreacion);

    puertos.puert[puertos.cantPuertos] = p;

    puertos.cantPuertos++;
}

DtPuerto** listarPuerto(int& cantPuertos)
{
    cantPuertos = puertos.cantPuertos;

    DtPuerto** arreglo = new DtPuerto*[cantPuertos];

    for(int i = 0; i < cantPuertos; i++)
    {
        DtPuerto *auxP = new DtPuerto(puertos.puert[i] -> getId(), puertos.puert[i] -> getNombre(), puertos.puert[i] -> getFechaCreacion(), puertos.puert[i] -> getCantArribos());

        arreglo[i] = auxP;
    }

    return arreglo;
}

DtArribo** obtenerInfoArribosEnPuerto(std::string idPuerto, int& cantArribos)
{
    std::cout << "entra a obtenerInfoArribosEnPuerto\n";
    Puerto * puerto = existePuerto(idPuerto);
    int length;
    
    if (puerto == NULL)
    {
        throw std::invalid_argument("NO EXISTE UN PUERTO CON EL ID: " + idPuerto);
        return NULL;
    }

    if(cantArribos <= puerto -> getCantArribos())
        length = cantArribos;
    else
        length = puerto -> getCantArribos();
    //En caso de que cantArribos sea mayor a la cantidad de arribos del puerto, se devueleve todos los arribos del puerto

    DtArribo ** arrayArribo = copiarArrayArribo(puerto -> getArribos(), length);
    
    return arrayArribo;
}

DtArribo ** copiarArrayArribo(Arribo * original, int cantArribos)
{
    DtArribo ** copia = new DtArribo*[cantArribos];

    for (int i = 0; i < cantArribos; i++)
    {
        std::cout << original[i].getFecha().getDia() << std::endl;
        std::cout << original[i].getFecha().getMes() << std::endl;
        std::cout << original[i].getFecha().getAnio() << std::endl;

        copia[i] -> setFecha(original[i].getFecha());
        copia[i] -> setCarga(original[i].getCarga());

        BarcoPesquero* barco_pesquero = dynamic_cast<BarcoPesquero*>(original[i].getBarco());
        BarcoPasajero* barco_pasajero = dynamic_cast<BarcoPasajero*>(original[i].getBarco());

        DtBarcoPasajero * copiaBarcoPasajero;
        DtBarcoPesquero * copiaBarcoPesquero;

        if (barco_pasajero != NULL)
        {  
            copiaBarcoPasajero = new DtBarcoPasajero();
            copiaBarcoPasajero -> setId(barco_pasajero -> getId());
            copiaBarcoPasajero -> setNombre(barco_pasajero -> getNombre());
            copiaBarcoPasajero -> setCantPasajeros(barco_pasajero -> getCantPasajeros());
            copiaBarcoPasajero -> setTamanio(barco_pasajero -> getTamanio());
            copia[i] -> setBarco(copiaBarcoPasajero);
        }
        else
        {
            copiaBarcoPesquero = new DtBarcoPesquero();
            copiaBarcoPesquero -> setId(barco_pesquero -> getId());
            copiaBarcoPesquero -> setNombre(barco_pesquero -> getNombre());
            copiaBarcoPesquero -> setCapacidad(barco_pesquero -> getCapacidad());
            copiaBarcoPesquero -> setCarga(barco_pesquero -> getCarga());
            copia[i] -> setBarco(copiaBarcoPasajero);
        }

    }
    return copia;
}

void eliminarArribos(std::string idPuerto, DtFecha fecha)
{
    Puerto * puerto = existePuerto(idPuerto);
    Arribo * arrayArribo;
    
    if (puerto == NULL)
    {
        throw std::invalid_argument("NO EXISTE UN PUERTO CON EL ID: " + idPuerto);
        return;
    }

    arrayArribo = puerto -> getArribos();
    
    for (int i = 0; i < puerto -> getCantArribos(); i++)
    {
        if (arrayArribo[i].getFecha() == fecha)
        {
            for (int j = i; j < puerto -> getCantArribos() - 1; j++)
            {
                arrayArribo[j] = arrayArribo[j + 1];
            }
        }
    }

    puerto -> setCantArribos(puerto -> getCantArribos() - 1);
}

/////////////////////////////////////////////////////////////////////

