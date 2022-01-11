#include "ExamenFinal.h"

ExamenFinal::ExamenFinal(string materie, int nota, string data, int puncte_bonus) :Examen(materie, nota, data){
    try
    {
        if( puncte_bonus < 0 || puncte_bonus > 10 )
            throw 1;
    }
    catch(int j )
    {
        cout << "Nota bonus trebuie sa fie un numar intre 0 si 10";
    }
    this->puncte_bonus = puncte_bonus;
}
void ExamenFinal::citire(istream& in) {
    Examen::citire(in);
    cout << "Puncte Bonus";
    in>>this->puncte_bonus;
}
void ExamenFinal::afisare(ostream &out) {
    Examen::afisare(out);
    out << "Puncte bonus: "<< this->puncte_bonus<<endl;
}
ExamenFinal& ExamenFinal::operator=(ExamenFinal &e) {
    Examen::operator=(e);
    this->puncte_bonus = e.puncte_bonus;
    return *this;
}
istream& operator >>(istream& in, ExamenFinal& p){
    p.citire(in);
    return in;
}
ostream& operator <<(ostream& out, ExamenFinal& p){
    p.afisare(out);
    return out;
}