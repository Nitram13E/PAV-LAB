#include "main.h"
#define MAX_BARCOS 50

    //TODOS LOS BARCOS DEL SISTEMA
    struct 
    {
        Barco* barcos[MAX_BARCOS];
        int tope=0;
    }*coleccionBarcos;
    

  

    //OPERACION G
    void listarBarcos();
    DtBarco** listarBarcos(int& cantBarcos);


    //OPERACION A
    /*void agregarBarco(DtBarco& barco){
        try{
            DtBarcoPasajero& dtBarcoPasajero = dynamic_cast<DtBarcoPasajero&>(barco);
            BarcoPasajero* barcoPas = new BarcoPasajero(dtBarcoPasajero.getId(), dtBarcoPasajero.getNombre(), dtBarcoPasajero.getCantPasajeros(), dtBarcoPasajero.getTamanio());
            coleccionBarcos.barcos[coleccionBarcos.tope]=barcoPas;
            coleccionBarcos.tope++;
        }catch(bad_cast){
            try{
                DtBarcoPesquero& dtBarcoPesquero = dynamic_cast<DtBarcoPesquero&>(barco);
                BarcoPesquero* barcoPes = new BarcoPesquero(dtBarcoPesquero.getId(), dtBarcoPesquero.getNombre(), dtBarcoPesquero.getCapacidad(), dtBarcoPesquero.getNombre()); 
                coleccionBarcos.barcos[coleccionBarcos.tope]=barcoPes;
                coleccionBarcos.tope++;
            }catch(bad_cast){}    
        }
    }*/

    //OPERACION G

    void listarBarcos()
    {
        std::cout << endl;
        int cant;
        DtBarcoPesquero* pesquero;
        DtBarcoPasajero* pasajero;
        DtBarco** dtbarcos = obtenerBarco(cant);
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
        int cant;
        for (int i = 0; i < cant; i++){
            barco=dynamic_cast<Barco>;

            if (m!=NULL)
            else
        }
    }

    void listarBarcos(){
        cout << endl;
        int cantVehiculos;
        DtBicicleta* bici;
        DtMonopatin* mono;
        DtVehiculo** dtvehiculos = obtenerVehiculos(cantVehiculos);
        for (int i = 0; i < cantVehiculos; i++){
            mono = dynamic_cast<DtMonopatin*>(dtvehiculos[i]);
            if (mono!=NULL)
                cout << "\n\n" << *(mono);
            else{
                bici = dynamic_cast<DtBicicleta*>(dtvehiculos[i]);
                if (bici!=NULL) cout << "\n\n" << *(bici);	
            }
        }
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