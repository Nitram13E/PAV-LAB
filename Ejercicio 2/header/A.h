#ifndef A_H
#define A_H

class B; 
class C;

class A
{
    private:
        int a;
        B * b;
        C * c;

    public:

        A();
        A(int, B*, C*);

        void setVal(int);
        void setB(B*);
        void setC(C*);

        void printer();
};

#endif