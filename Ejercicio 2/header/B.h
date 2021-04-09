#ifndef B_H
#define B_H

class A; 
class C;

class B
{
    private:
        int b;
        A * a;
        C * c;

    public:
        B();
        B(int, A*, C*);

        void setVal(int);
        void setA(A*);
        void setC(C*);
        void printer();
};

#endif