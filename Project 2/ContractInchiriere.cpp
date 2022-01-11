#include "ContractInchiriere.h"


ContractInchiriere::ContractInchiriere(int nrContract, int an, string nume, string furnizor, int valoare,
                                       int perioada) :Contract( nrContract, an, nume, furnizor, valoare){
    this->perioada = perioada;
}
ContractInchiriere::ContractInchiriere(ContractInchiriere &c) :Contract(c) {
    this->perioada = c.perioada;
}
ContractInchiriere::~ContractInchiriere()  {

}
void ContractInchiriere::citire(istream &in) {
    Contract::citire(in);
    cout << "Perioada contractului in luni: ";
    in>>this->perioada;
}
void ContractInchiriere::afisare(ostream &out) {
    Contract::afisare(out);
    out << "Perioada contractului in luni: ";
    out << this->perioada<< endl;
}
istream& operator>>(istream &in, ContractInchiriere &c){
    c.citire(in);
    return in;
}
ostream& operator<<(ostream &out, ContractInchiriere &c){
    c.afisare(out);
    return out;
}
ContractInchiriere& ContractInchiriere::operator=(ContractInchiriere &c) {
    this->nrContract = c.nrContract;
    this->an = c.an;
    this->nume = c.nume;
    this->furnizor = c.furnizor;
    this->valoare = c.valoare;
    this->perioada = c.perioada;
    return *this;
}
int ContractInchiriere::get_perioada() {
    return this->perioada;
}