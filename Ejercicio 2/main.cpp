#include <stdlib.h>

#include "header/A.h"
#include "header/B.h"
#include "header/C.h"


int main()
{
    A * a = new A(1, NULL, NULL);
    B * b = new B(2, a, NULL);
    C * c = new C(3, a, b);

    a -> setB(b);
    a -> setC(c);

    b -> setA(a);
    b -> setC(c);

    a -> printer();
    b -> printer();
    c -> printer();

    return 0;
}