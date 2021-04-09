#include <iostream>
#include <unistd.h>
#include <limits>
#include <locale.h>
#include <wchar.h>

#include "Class/header/Barco.h"
#include "Class/header/Puerto.h"

#include "DataTypes/header/DtBarco.h"
#include "Class/header/Barcos/BarcoPasajero.h"
#include "Class/header/Barcos/BarcoPesquero.h"
#include "DataTypes/header/Barcos/DtBarcoPasajero.h"
#include "DataTypes/header/Barcos/DtBarcoPesquero.h"
#include "DataTypes/header/DtPuerto.h"
#include "DataTypes/header/DtArribo.h"

#define MAX_BARCOS 10
#define MAX_PUERTOS 10

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

///////////////OPERACIONES AUXILIARES/////////////////

Puerto* existePuerto(std::string idPuerto);

Barco* existeBarco(std::string idBarco);

void efectuarCarga(Barco* barco, float cargaDespacho);

Barco * convertirBarco(DtBarco& barco);

///////////////OPERACIONES///////////////////////////

void agregarPuerto(std::string id, std::string nombre, DtFecha fechaCreacion);

void agregarBarco(DtBarco& barco);

DtPuerto** listarPuerto(int& cantPuertos);

void agregarArribo(std::string idPuerto, std::string idBarco, DtFecha fecha, float cargaDespacho);

DtArribo** obtenerInfoArribosEnPuerto(std::string idPuerto, int& cantArribos);

void eliminarArribos(std::string idPuerto, DtFecha fecha);

DtBarco** listarBarcos(int& cantBarcos);

void cargarDatos();

void presEnter();

void menu()
{
    setlocale(LC_ALL, "");

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

                    if (puertos.cantPuertos < MAX_PUERTOS)
                    {
                        std:: string idPuerto;
                        std:: string nomPuerto;
                        int dia;
                        int mes;
                        int anio;
                        
                        std::cout << "AGREGAR PUERTO\n" << std::endl;
                        
                        std::cout << " - Ingrese idPuerto: ";
                        std::cin >> idPuerto;

                        std::cout << " - Ingrese nombre: ";
                        std::cin >> nomPuerto;

                        std::cout << "\nIngrese fecha de creacion: " << std::endl;

                        std::cout << "- Dia: ";
                        std::cin >> dia;
                        
                        std::cout << "- Mes: ";
                        std::cin >> mes;

                        std::cout << "- Año: ";
                        std::cin >> anio;

                        system("clear");

                        try
                        {
                            agregarPuerto(idPuerto, nomPuerto, DtFecha(dia, mes, anio));
                            
                            std::cout << "\nSe ha agregado el puerto con id " << idPuerto << " correctamente!" << std::endl;
                        }
                        catch (std::invalid_argument& i)
                        {
                            std::cout << "\n" << i.what() << std::endl;
                            std::cout << "\nVuelva a intentar" << std::endl;
                        }
                    }
                    else
                    {
                        std::cout << "La lista de puertos esta llena.\n" << std::endl;
                    }

                    presEnter();
                    break;
                }
            
            case 2://Agregar Barco
                {   
                    system("clear");
                    
                    if (barcos.cantBarcos < MAX_BARCOS)
                    {

                        int op;
                        std::string idBarco;
                        std::string nombreBarco;

                        std::cout << "AGREGAR BARCO\n" << std::endl;
                        std::cout << "Elija tipo de barco: " << std::endl << std::endl;
                        std::cout << "1 - BarcoPesquero " << std::endl;
                        std::cout << "2 - BarcoPasajero " << std:: endl;
                        std::cout << "Opcion: ";
                        std::cin >> op;
                        
                        if (op == 1)
                        {
                            system("clear");

                            int capacidad;
                            int carga;
                            
                            std::cout << "Barco Pesquero" << std::endl << std::endl;

                            std::cout << "- Ingrese idBarco: ";
                            std::cin >> idBarco;

                            std::cout << "- Ingrese nombre: ";
                            std::cin >> nombreBarco;

                            std::cout << "- Ingrese capacidad: ";
                            std::cin >> capacidad;

                            std::cout << "- Ingrese carga: ";
                            std::cin >> carga;

                            if (carga <= capacidad)
                            {
                                DtBarcoPesquero pesquero = DtBarcoPesquero(idBarco, nombreBarco, capacidad, carga);
                                
                                try
                                {
                                    agregarBarco(pesquero);
                                    std::cout << "\nSe ha agregado el barco con id " << idBarco << " correctamente!" << std::endl;
                                }
                                catch (std::invalid_argument& inv)
                                {
                                    std::cout << "\n" << inv.what() << std::endl;
                                }
                            }
                            else
                            {
                                system("clear");
                                std::cout  << "\n" <<  "Error al agregar barco: La carga supera a la capacidad" << std::endl;
                            }
                        }
                        else if (op == 2)
                        {
                            system("clear");

                            int cantPasajeros;
                            int tamanio;

                            std::cout << "Barco Pasajero" << std::endl << std::endl;

                            std::cout << "- Ingrese id: ";
                            std::cin >> idBarco;

                            std::cout << "- Ingrese nombre: ";
                            std::cin >> nombreBarco;

                            std::cout << "- Ingrese cantidad de pasajeros: ";
                            std::cin >> cantPasajeros;

                            std::cout << "\nTamaño del barco:\n- 1: bote\n- 2: crucero\n- 3: galeon\n- 4: transatlantico" << std::endl;
                            std::cout << "- Ingrese el tamaño (1, 2, 3 o 4): ";
                            std::cin >> tamanio;

                            TipoTamanio tipo = static_cast<TipoTamanio>(tamanio);

                            DtBarcoPasajero pasajero = DtBarcoPasajero(idBarco, nombreBarco, cantPasajeros, tipo);
                            
                            try
                            {   
                                agregarBarco(pasajero);
                                std::cout << "\nSe ha agregado el barco con id " << idBarco << " correctamente!" << std::endl;
                            }
                            catch (std::invalid_argument& error)
                            {
                                std::cout << "\n" << error.what() << std::endl;
                            }
                        }
                    }
                    else 
                    {
                        std::cout << "La lista de barcos esta llena.\n" << std::endl;
                    }

                    presEnter();
                    break;
                }

            case 3: //Listar Puerto
                {
                    system("clear");

                    int cantP;

                    std::cout << "LISTA DE PUERTOS\n" << std::endl;

                    DtPuerto** lista = listarPuerto(cantP);

                    if (cantP == 0)
                    {
                        std::cout << "\nNo existen puertos ingresados" << std::endl; 
                    }
                    else
                    {
                        for (int i = 0; i < cantP; i++)
                        {
                            std::cout << "---------------------------------\n" << std::endl;
                            std::cout << *lista[i] << std::endl;
                            std::cout << "---------------------------------\n" << std::endl;
                        }
                    }

                    presEnter();
                    break;
                }
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

                    std::cout << "Dia: ";
                    std::cin >> dia;
                    
                    std::cout << "Mes: ";
                    std::cin >> mes;

                    std::cout << "Año: ";
                    std::cin >> anio;

                    std::cout << "- Ingrese carga de despacho: ";
                    std::cin >> cargaDespacho;

                    system("clear");
                    
                    try
                    {
                        agregarArribo(idPuerto, idBarco, DtFecha(dia, mes, anio), cargaDespacho);
                        std::cout << "\nSe ha agregado el arribo correctamente!" << std::endl;
                    }
                    catch (std::invalid_argument& error)
                    {
                        std::cout << "\n" << error.what() << std::endl;
                    }

                    presEnter();
                    break;
                }

            case 5: //obtenerInfoArribosEnPuerto
                {
                    system("clear");

                    std::string idPuerto;
                    int cantArribos; 
                    DtArribo** arrayArribos;

                    std::cout << "OBTENER INFO ARRIBOS \n- Ingrese idPuerto: ";
                    std::cin >> idPuerto;

                    system("clear");
                    
                    std::cout << "OBTENER INFO ARRIBOS" << std::endl << std::endl;

                    try
                    {
                        arrayArribos = obtenerInfoArribosEnPuerto(idPuerto, cantArribos);

                        if(cantArribos == 0)
                        {
                            std::cout << "\nNo ha habido ningun arribo en el puerto ingresado" << std::endl;
                        }
                        else
                        {
                            for (int i = 0; i < cantArribos; i++)
                            {
                                std::cout << "---------------------------------\n" << std::endl;
                                std::cout << *arrayArribos[i] << std::endl;
                                std::cout << "---------------------------------\n" << std::endl;
                            }
                        }
                    }
                    catch(std::invalid_argument& error)
                    {
                        std::cout << "\n" << error.what() << std::endl;
                        std::cout << "\nVuelva a intentar" << std::endl;
                    }

                    presEnter();
                    break;
                }

            case 6: //eliminarArribos
                {
                    system("clear");
                    
                    std::string idPuerto;
                    int dia, mes, anio;

                    std::cout << "ELIMINAR ARRIBO" << std::endl << std::endl;

                    std::cout << "- Ingrese idPuerto: ";
                    std::cin >> idPuerto;
                    std::cout << "- Ingrese una fecha: " << std::endl;

                    std::cout << "Dia: ";
                    std::cin >> dia;
                    
                    std::cout << "Mes: ";
                    std::cin >> mes;

                    std::cout << "Año: ";
                    std::cin >> anio;

                    try
                    {
                        eliminarArribos(idPuerto, DtFecha(dia, mes, anio));
                    }
                    catch (std::invalid_argument& error)
                    {
                        std::cout << "\n" << error.what() << std::endl;
                    }

                    presEnter();
                    break;
                }
            case 7: //Listar Barcos
                {
                    system("clear");

                    int barco;

                    std::cout << "LISTA DE BARCOS" << std::endl << std::endl;

                    DtBarco ** barcolistado = listarBarcos(barco);

                    if (barco == 0)
                    {
                        std::cout << "\nNo hay ningun barco ingresado" << std::endl;
                    }
                    else
                    {
                        for (int i = 0; i < barco; i++)
                        {
                            DtBarcoPasajero * pasa = dynamic_cast<DtBarcoPasajero*>(barcolistado[i]);

                            if (pasa == NULL)
                            {
                                DtBarcoPesquero * pesq = dynamic_cast<DtBarcoPesquero*>(barcolistado[i]);

                                std::cout << "---------------------------------\n" << std::endl;
                                std::cout << *pesq << std::endl;
                                std::cout << "---------------------------------\n" << std::endl;
                            }
                            else
                            {
                                std::cout << "---------------------------------\n" << std::endl;
                                std::cout << *pasa << std::endl;
                                std::cout << "---------------------------------\n" << std::endl;
                            }
                        }
                    }                      
                    
                    presEnter();
                    break;
                }
            
            case 8: //Salir
                {
                    std::cout << "Saliendo.." << std::endl;
                    sleep(2);

                    break;
                }
            default: //Opcion incorrecta
            
                std::cout << "\n" << "Por favor, introduzca una opcion valida." << std::endl;
                sleep(1);

                break;
        }
    }
    while (opcion != 8);
}

void presEnter()
{
    std::string enter;
    std::getline(std::cin, enter);
    std::cout << "Presiona enter para continuar...";
    std::getline(std::cin, enter);
}

///////////////OPERACIONES AUXILIARES////////////////

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

    if (pesq == NULL)
    {
        if (cargaDespacho != 0)
        {
            throw std::invalid_argument("Un barco pasajero no puede tener carga.");
        }

        return;
    }

    if (cargaDespacho > 0)
    {
        pesq -> arribar(cargaDespacho);
    }
    else //Si el valor de carga que se despacha es negativo o 0
    {
        pesq -> partir(cargaDespacho);
    }
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

///////////////OPERACIONES///////////////////////////

void agregarPuerto(std::string id, std::string nombre, DtFecha fechaCreacion)
{
    if (existePuerto(id) != NULL)
    {
        throw std::invalid_argument("Ya existe el puerto con id " + id);
    }
  
    Puerto* p = new Puerto(id,nombre,fechaCreacion);

    puertos.puert[puertos.cantPuertos] = p;

    puertos.cantPuertos++;
}

void agregarBarco(DtBarco& barco)
{
    for (int i = 0; i < barcos.cantBarcos; i++)
    {
        if (barco.getId() == barcos.bar[i] -> getId())
        {
            throw std::invalid_argument("El barco ya existe en el sistema.");
        }
    }

    barcos.bar[barcos.cantBarcos] = convertirBarco(barco);
    barcos.cantBarcos++;
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

void agregarArribo(std::string idPuerto, std::string idBarco, DtFecha fecha, float cargaDespacho)
{
    Puerto* puerto = existePuerto(idPuerto);
    
    Barco* barco = existeBarco(idBarco);

    if (puerto == NULL || barco == NULL)//Excepecion si no existe barco o no existe puerto
    {
        throw std::invalid_argument("No se pudo agregar un arribo.");
    }

    if (puerto -> getCantArribos() >= MAX_ARRIBO)
    {
        throw std::invalid_argument("Cantidad de arribos en el puerto excedida. ");
    }

    efectuarCarga(barco, cargaDespacho);

    Arribo * arribo = new Arribo(fecha, cargaDespacho, barco);

    puerto -> agregarArribos(arribo);
}

DtArribo** obtenerInfoArribosEnPuerto(std::string idPuerto, int& cantArribos)
{
    Puerto * puerto = existePuerto(idPuerto);
    
    if (puerto == NULL)
    {
        throw std::invalid_argument("No existe un puerto con id " + idPuerto);
    }

   cantArribos = puerto -> getCantArribos();

   DtArribo** arrayArribo = puerto -> getDtArribos();

   return arrayArribo;
}

void eliminarArribos(std::string idPuerto, DtFecha fecha)
{
    Puerto * puerto = existePuerto(idPuerto);

    if (puerto == NULL)
    {
        throw std::invalid_argument("No existe un puerto con id " + idPuerto);
    }

    Arribo ** arrayArribo = puerto -> getArribos();

    if (puerto -> getCantArribos() == 0)
    {
        throw std::invalid_argument("No existen arribos en el puerto: " + idPuerto);
    }

    for (int i = 0; i < puerto -> getCantArribos(); i++)
    {
        if (arrayArribo[i] -> getFecha() == fecha)
        {
            delete arrayArribo[i];

            for (int arribo = i; arribo < puerto -> getCantArribos() - 1; arribo++)
            {
                arrayArribo[arribo] = arrayArribo[arribo + 1];   
            }

            puerto -> setCantArribos(puerto -> getCantArribos() - 1);
        }
    }
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

void cargarDatos()
{
    try
    {
        //BARCOS
        int tamanio = 1;
        
        TipoTamanio tipo = static_cast<TipoTamanio>(tamanio); 

        DtBarcoPasajero pasa = DtBarcoPasajero("10", "titanic", 341, tipo);
        
        agregarBarco(pasa);

        tamanio = 2;
        
        tipo = static_cast<TipoTamanio>(tamanio); 

        pasa = DtBarcoPasajero("11", "concordia", 241, tipo);
        
        agregarBarco(pasa);

        tamanio = 3;
        
        tipo = static_cast<TipoTamanio>(tamanio); 

        pasa = DtBarcoPasajero("12", "diamond princess", 312, tipo);
        
        agregarBarco(pasa);

        DtBarcoPesquero pes = DtBarcoPesquero("13", "santa maria", 234, 10);
        
        agregarBarco(pes);

        pes = DtBarcoPesquero("14", "pinta", 243, 5);

        agregarBarco(pes);

        //PUERTOS

        DtFecha fecha = DtFecha(1, 2, 1910);

        agregarPuerto("100", "MVD", fecha);

        fecha = DtFecha(15, 6, 1905);

        agregarPuerto("101", "BSAS", fecha);

        fecha = DtFecha(19, 12, 1900);

        agregarPuerto("102", "NYC", fecha);

        //ARRIBOS
        
        fecha = DtFecha(9, 1, 2020);

        agregarArribo("100", "10", fecha, 0);

        fecha = DtFecha(12, 2, 2021);

        agregarArribo("100", "11", fecha, 0);

        fecha = DtFecha(20, 4, 2020);

        agregarArribo("100", "13", fecha, 2);

        fecha = DtFecha(21, 4, 2020);

        agregarArribo("101", "14", fecha, -52);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


int main()
{
    cargarDatos();
    menu();
    
    return 0;
}