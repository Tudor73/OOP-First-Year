#ifndef MAIN_CPP_PARTIAL_H
#define MAIN_CPP_PARTIAL_H
#include "Examen.h"
#include <iostream>

class Partial: public Examen{
private:
    double nota_oral;
public:
    Partial( string = "", double = 0, string = "", double = 0);
    void citire(istream&);
    void afisare(ostream&);
    Partial& operator=(Partial &p);
    friend istream& operator>>(istream&, Partial& );
    friend ostream& operator<<(ostream&, Partial& );
};
#endif //MAIN_CPP_PARTIAL_H
