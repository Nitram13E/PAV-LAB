#ifndef BARCO
#define BARCO

#include <string>
#include "../../DataTypes/header/DtBarco.h"

class Barco
{
private:
    std::string id;
    std::string nombre;

public:
    Barco();
    Barco(std::string, std::string);
    ~Barco();

    void setId(std::string);
    std::string getId();

    void setNombre(std::string);
    std::string getNombre();

    virtual void arribar(float) = 0;

    virtual DtBarco* getDtBarco() = 0;
};

#endif