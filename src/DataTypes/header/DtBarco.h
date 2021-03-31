#ifndef DTBARCO
#define DTBARCO

#include <string>

class DtBarco
{
private:
    std::string id;
    std::string nombre;

public:
    DtBarco();
    DtBarco(std::string, std::string);
    ~DtBarco();

    void setId(std::string);
    std::string getId();

    void setNombre(std::string);
    std::string getNombre();

};



#endif