#include "Dosar.h"


Dosar::Dosar() {
    this->nrContracteInchiriere = 0;
    this-> contracte = nullptr;
}
Dosar::Dosar(ContractInchiriere &v, int nr) {
    this->contracte = &v;
    this->nrContracteInchiriere = nr;
}
Dosar::~Dosar() {
    delete[] this->contracte;
    this->contracte = nullptr;
    this->nrContracteInchiriere = 0;
}
void Dosar::set_contracte(ContractInchiriere &v, int nr) {
    this->contracte = &v;
    this->nrContracteInchiriere = nr;
}
ContractInchiriere* Dosar::get_contracte() {
    return this->contracte;
}
int Dosar::get_nr_contracte() {
    return this->nrContracteInchiriere;
}
int Dosar::get_valoarea_totala() {
    int suma_totala = 0;
    if(this->contracte == nullptr)
        return 0;
    else{
        for(int i = 0; i< this->nrContracteInchiriere; i++){
            int val = this->contracte[i].get_valoare();
            suma_totala+= val;
        }
    }
    return suma_totala;
}
void Dosar::valoare_pe_perioada(){
    if(this->contracte == nullptr){
        cout << "Dosarul este gol ";
    }
    else{
        for (int i = 0; i< this->nrContracteInchiriere; i++){
            int val = contracte[i].get_valoare();
            int p = contracte[i].get_perioada();
            int nr = contracte[i].get_nrContract();
            cout <<"Contractul cu numarul "<< nr <<" are valoarea "<< val<< " pe o perioada de "<< p << " luni ";
            cout << endl;
        }
    }
}
void Dosar::citire(istream &in) {
    cout << "Numarul de contracte de inchiriere: ";
    in >> this->nrContracteInchiriere;
    contracte = new ContractInchiriere[nrContracteInchiriere];
    for(int i = 0; i< nrContracteInchiriere; i++){
        cout << "Contractul "<< i+1<<endl;
        in >> this->contracte[i];
    }
}
void Dosar::afisare(ostream &out) {
    for(int i = 0; i< nrContracteInchiriere;i++){
        out << endl;
        out << contracte[i];
    }
}
istream& operator>>(istream& in, Dosar& d){
    d.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Dosar& d){
    d.afisare(out);
    return out;
}
