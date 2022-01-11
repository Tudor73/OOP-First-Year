#include "Partial.h"


Partial::Partial(string materie, double nota, string data, double nota_oral) :Examen(materie, nota, data){
    try
    {
        if(nota_oral < 0 || nota_oral > 10)
            throw 1;
    }
    catch(int j)
    {
        cout << "Nota oral trebuie sa fie un numar intre 0 si 10";
        exit(EXIT_FAILURE);
    }
    this->nota_oral = nota_oral;
}
void Partial::citire(istream& in) {
    Examen::citire(in);
    cout << "Nota oral: ";
    in>>this->nota_oral;
}
void Partial::afisare(ostream &out) {
    Examen::afisare(out);
    out << "Nota oral: "<< this->nota_oral<<endl;
}
Partial& Partial::operator=(Partial &p) {
    Examen::operator=(p);
    this->nota_oral = p.nota_oral;
    return *this;
}
istream& operator >>(istream& in, Partial& p){
    p.citire(in);
    return in;
}
ostream& operator <<(ostream& out, Partial& p){
    p.afisare(out);
    return out;
}
