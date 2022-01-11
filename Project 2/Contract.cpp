#include "Contract.h"
#include <iostream>
int Contract::nr;

Contract::Contract(int nrContract, int an, string nume, string furnizor, int valoare) {
    this->nrContract = nrContract;
    this->an = an;
    this->nume= nume;
    this->furnizor = furnizor;
    this->valoare = valoare;
    nr++;
}
Contract::Contract(Contract &c) {
    this->nrContract = c.nrContract;
    this->an = c.an;
    this->nume = c.nume;
    this->furnizor = c.furnizor;
    this->valoare = c.valoare;
    nr++;
}
Contract::~Contract() {

}
void Contract::citire(istream &in) {
    cout << "Numarul contractului: ";
    in>> this->nrContract;
    cout << "Anul semnarii contractului: ";
    in>> this->an;
    cout << "Numele beneficiarului: ";
    in>> this->nume;
    cout << "Numele furnizorului: ";
    in>> this->furnizor;
    cout << "Valoarea totala a produsului: ";
    in>> this->valoare;
}
void Contract::afisare(ostream &out) {
    cout << "Numarul contractului: ";
    out<< this->nrContract<<endl;
    cout << "Anul semnarii contractului: ";
    out<< this->an<<endl;
    cout << "Numele beneficiarului: ";
    out<< this->nume<<endl;
    cout << "Numele furnizorului: ";
    out<< this->furnizor<<endl;
    cout << "Valoarea totala a produsului: ";
    out<< this->valoare<<endl;
}
istream& operator>>(istream &in, Contract &c){
    c.citire(in);
    return in;
}
ostream& operator<<(ostream &out, Contract &c){
    c.afisare(out);
    return out;
}
Contract& Contract::operator=(Contract c) {
    this->nrContract = c.nrContract;
    this->an = c.an;
    this->nume = c.nume;
    this->furnizor = c.furnizor;
    this->valoare = c.valoare;
    return *this;
}
int Contract::get_valoare() {
    return this->valoare;
}
int Contract::get_nrContract() {
    return this->nrContract;
}
int Contract::nr_contracte() {
    return Contract::nr;
}
