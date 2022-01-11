#include "Examen.h"


int Examen::nr;
Examen::Examen(string materie, double nota, string data):id(++nr) {
    this->materie = materie;
    this->data = data;
    try{
        if(nota< 0 || nota > 10)
            throw 1;
    }
    catch(int j)
    {
        cout << "Nota trebuie sa fie un numar intre 0 si 10";
        exit(EXIT_FAILURE);
    }
    this-> nota = nota;
}
Examen::Examen(Examen &e):id(e.id) {
    this->materie = e.materie;
    this->data = e.data;
    this->nota = e.nota;
}
Examen::~Examen(){

}
void Examen::citire(istream &in) {
    cout << "Materie: ";
    in>>this->materie;
    cout << "Data: ";
    in>>this->data;
    cout << "Nota: ";
    string p;
    in>>p;
    double n;
    char *q=new char [p.length()+1];
    strcpy(q,p.c_str());
    n=atof(q);
    try
    {
        if( n < 0 || n > 10 )
            throw 1;
    }
    catch(int j)
    {
        cout << "Nota trebuie sa fie un numar intre 0 si 10";
        exit(EXIT_FAILURE);
    }
    this->nota = n;
}
void Examen::afisare(ostream &out) {
    out << "id examen: "<< this->id << endl;
    out << "Materie: "<< this->materie<< endl;
    out << "Data: "<< this->data<< endl;
    out << "Nota: "<< this->nota<< endl;
}
int Examen::get_nr_examene() {
    return Examen::nr;
}
int Examen::get_id_examen() const {
    return this->id;
}
int Examen::get_nota() const {
    return this->nota;
}
Examen& Examen::operator=(Examen &e) {
    if (this != &e){
        this->materie = e.materie;
        this->data = e.data;
        this->nota = e.nota;
    }
    return *this;
}
istream& operator>>(istream& in, Examen& e){
    e.citire(in);
    return in;
}
ostream& operator<<(ostream& out, Examen& e){
    e.afisare(out);
    return out;
}