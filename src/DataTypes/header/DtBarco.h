#ifndef DTBARCO
#define DTBARCO

#include <iostream>

class DtBarco
{
private:
    std::string id;
    std::string nombre;

public:
    DtBarco();
    DtBarco(std::string, std::string);
    virtual ~DtBarco();
   
    std::string getId();

    std::string getNombre();

    friend std::ostream& operator << (std::ostream&, DtBarco);
};

#endif