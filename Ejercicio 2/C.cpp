#include "header/C.h"
#include "header/A.h"
#include "header/B.h"

#include <iostream>

C::C()
{
}

C::C(int c, A * a, B * b)
{
    this -> a = a;
    this -> b = b;
    this -> c = c;
}

void C::setVal(int val)
{
    this -> c = val;
}

void C::setA(A* a)
{
    this -> a = a;
}

void C::setB(B* b)
{
    this -> b = b;
}

void C::printer()
{
    std::cout << "Esta es la clase C, con valor: " << this -> c << std::endl;
}