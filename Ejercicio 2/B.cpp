#include "header/B.h"
#include "header/A.h"
#include "header/C.h"

#include <iostream>

B::B()
{
}

B::B(int b, A * a, C * c)
{
    this -> a = a;
    this -> b = b;
    this -> c = c;
}

void B::setVal(int val)
{
    this -> b = val;
}
void B::setA(A* a)
{
    this -> a = a;
}
void B::setC(C*)
{
    this -> c = c;
}

void B::printer()
{
    std::cout << "Esta es la clase B, con valor: " << this -> b << std::endl;
}