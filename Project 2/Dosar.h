#ifndef OOP_FIRST_YEAR_DOSAR_H
#define OOP_FIRST_YEAR_DOSAR_H

#include <iostream>
#include "ContractInchiriere.h"

class Dosar {
private:
    int nrContracteInchiriere;
    ContractInchiriere* contracte;
public:
    Dosar();
    Dosar(ContractInchiriere&, int);
    ~Dosar();
    void set_contracte(ContractInchiriere&, int);
    void citire(istream& in);
    void afisare(ostream& out);
    ContractInchiriere* get_contracte();
    int get_nr_contracte();
    int get_valoarea_totala();
    void valoare_pe_perioada();
    friend istream& operator>>(istream& in, Dosar& d);
    friend ostream& operator<<(ostream& out, Dosar& d);

};

#endif //OOP_FIRST_YEAR_DOSAR_H
