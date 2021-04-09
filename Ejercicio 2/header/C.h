#ifndef C_H
#define C_H

class A;
class B;

class C
{
    private:
        int c;
        A * a;
        B * b;

    public:
        C();
        C(int, A*, B*);

        void setVal(int);
        void setA(A*);
        void setB(B*);
        void printer();
};

#endif