#ifndef OOP_FIRST_YEAR_CONTRACTINCHIRIERE_H
#define OOP_FIRST_YEAR_CONTRACTINCHIRIERE_H

#include "Contract.h"
#include <iostream>

class ContractInchiriere: public Contract{
private:
    int perioada;
public:
    ContractInchiriere(int nrContract = 0, int an = 0, string nume = "", string furnizor = "", int valoare = 0, int perioada = 0);
    ContractInchiriere(ContractInchiriere &c);
    ~ContractInchiriere();
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream& in, ContractInchiriere &c);
    friend ostream& operator<<(ostream& in, ContractInchiriere &c);
    ContractInchiriere& operator=(ContractInchiriere &c);
    int get_perioada();

};

#endif //OOP_FIRST_YEAR_CONTRACTINCHIRIERE_H
