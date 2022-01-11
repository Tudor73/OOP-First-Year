#ifndef MAIN_CPP_EXAMEN_H
#define MAIN_CPP_EXAMEN_H
#include <iostream>
#include <string.h>

class Examen{
protected:
    const int id;
    string materie;
    string data;
    double nota;
    static int nr;
public:
    Examen( string = "", double = 0, string = "");
    Examen( Examen & e);
    virtual ~Examen();
    virtual void citire(istream& in);
    virtual void afisare(ostream& out);
    static int get_nr_examene() ;
    int get_id_examen() const;
    int get_nota() const;
    Examen& operator=(Examen &e);
    friend istream& operator>>(istream&, Examen&);
    friend ostream& operator<<(ostream&, Examen&);
};

#endif //MAIN_CPP_EXAMEN_H
