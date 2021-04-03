#include "main.h"
#define MAX_BARCOS 50

    //TODOS LOS BARCOS DEL SISTEMA
    struct 
    {
        Barco* barcos[MAX_BARCOS];
        int tope;
    } coleccionBarcos;
    

  

    //OPERACION G
    void listarBarcos();
    DtBarco** listarBarcos(int& cantBarcos);


    //OPERACION G

    void listarBarcos()
    {
        std::cout << std::endl;
        int cant;
        DtBarcoPesquero* pesquero;
        DtBarcoPasajero* pasajero;
        DtBarco** dtbarcos = listarBarcos(cant);
        for (int i = 0; i < cant; i++){
            pasajero = dynamic_cast<DtBarcoPasajero*>(dtbarcos[i]);
            if (pasajero!=NULL) std::cout << "\n\n" << *(pasajero);
            else{
                pesquero = dynamic_cast<DtBarcoPesquero*>(dtbarcos[i]);
                if (pesquero!=NULL) std::cout << "\n\n" << *(pesquero);	
            }//end else
        }//end for
    }

    DtBarco** listarBarcos(int& cantBarcos){
        DtBarco** dtbarcos = new DtBarco*[coleccionBarcos.tope];
        DtBarcoPesquero* dtpes;
        DtBarcoPasajero* dtpas;
        cantBarcos=coleccionBarcos.tope;
        for(int i=0;i<cantBarcos;i++){
            if(BarcoPesquero* pes = dynamic_cast<BarcoPesquero*>(coleccionBarcos.barcos[i])){
                    dtpes = new DtBarcoPesquero(pes->getId(), pes->getNombre(), pes->getCapacidad(),pes->getCarga());
                    dtbarcos[i]=dtpes;
            }else{
                if(BarcoPasajero* pas = dynamic_cast<BarcoPasajero*>(coleccionBarcos.barcos[i])){
                        dtpas = new DtBarcoPasajero(pas->getId(), pas->getNombre(), pas->getCantPasajeros(), pas->getTamanio());
                        dtbarcos[i]=dtpas;
                }
            }
        }
        return dtbarcos;
    }

    /*
    Devuelve un arreglo con información de los barcos registrados en el sistema.
    El parámetro cantBarcos es un parámetro de salida donde se devuelve la
    cantidad de barcos devueltos por la operación (corresponde a la cantidad de
    instancias de DtBarco retornadas).

    */
int main()
{   
    BarcoPasajero * pas = new BarcoPasajero();

    BarcoPesquero * pesq = new BarcoPesquero();
    
    std::cout<<"MENU"<<std::endl;

    std::cout<<"INGRESE CANT DE BARCOS"<<std::endl;



    return 0;
}