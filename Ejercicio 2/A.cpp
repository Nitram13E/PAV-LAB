#include "header/A.h"
#include "header/B.h"
#include "header/C.h"

#include <iostream>

A::A()
{
}

void A::setVal(int val)
{
    this -> a = val;
}

void A::setB(B* b)
{
    this -> b = b;
}

void A::setC(C* c)
{
    this -> c = c;
}

A::A(int a, B * b, C * c)
{
    this -> a = a;
    this -> b = b;
    this -> c = c;
}

void A::printer()
{
    std::cout << "Esta es la clase A, con valor: " << this -> a << std::endl;
}