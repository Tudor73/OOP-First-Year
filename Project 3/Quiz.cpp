#include "Quiz.h"

Quiz::Quiz(string materie, int nota, string data, int nr_itemi_grila) :Examen(materie, nota, data){
    this->nr_itemi_grila = nr_itemi_grila;
}
void Quiz::citire(istream& in) {
    Examen::citire(in);
    cout << "Numar itemi grila: ";
    in>>this->nr_itemi_grila;
}
void Quiz::afisare(ostream &out) {
    Examen::afisare(out);
    out << "Numar itemi grila: "<< this->nr_itemi_grila<<endl;
}
Quiz& Quiz::operator=(Quiz &q) {
    Examen::operator=(q);
    this->nr_itemi_grila = q.nr_itemi_grila;
    return *this;
}
istream& operator >>(istream& in, Quiz& p){
    p.citire(in);
    return in;
}
ostream& operator <<(ostream& out, Quiz& p){
    p.afisare(out);
    return out;
}
