#ifndef MAIN_CPP_ELEV_H
#define MAIN_CPP_ELEV_H
#include <iostream>
#include <string.h>

using namespace std;
class Elev{
private:
    string nume;
    string prenume;
    int an_de_studiu;
    int id_examen;
public:
    Elev(string = "", string = "", int = 1, int = 1);
    int get_id_examen() const;
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream& in, Elev &e);
    friend ostream& operator<<(ostream& out, Elev &e);
};
Elev::Elev(string nume, string prenume, int an, int id_examen) {
    this->nume = nume;
    this->prenume = prenume;
    this->an_de_studiu = an;
    this->id_examen = id_examen;
}
int Elev::get_id_examen() const {
    return this->id_examen;
}
void Elev::citire(istream &in) {
    cout << "Nume: ";
    in >> this->nume;
    cout << "Prenume: ";
    in>> this->prenume;
    cout << "an de studiu ";
    in >> this->an_de_studiu;
    cout << "id examen: ";
    in>> this->id_examen;
}
void Elev::afisare(ostream &out) {
    out <<"Nume: "<< this->nume << endl;
    out << "Prenume: "<< this->prenume<<endl;
    out << "An de studiu: "<<this->an_de_studiu<<endl;
    out<< "Examen: "<<this->id_examen<<endl;
}
istream& operator>>(istream& in, Elev &e){
    e.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Elev &e){
    e.afisare(out);
    return out;
}

#endif //MAIN_CPP_ELEV_H
