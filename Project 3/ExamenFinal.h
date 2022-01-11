#ifndef MAIN_CPP_EXAMENFINAL_H
#define MAIN_CPP_EXAMENFINAL_H
#include <iostream>
#include "Examen.h"

class ExamenFinal: public Examen{
private:
    int puncte_bonus;
public:
    ExamenFinal(string = "", int = 0, string = "", int = 0);
    void citire(istream&) ;
    void afisare(ostream&);
    ExamenFinal& operator=(ExamenFinal &e);
    friend istream& operator>>(istream&, ExamenFinal& );
    friend ostream& operator<<(ostream&, ExamenFinal& );
};

#endif //MAIN_CPP_EXAMENFINAL_H
