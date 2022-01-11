#ifndef MAIN_CPP_CATALOGINDIVIDUAL_H
#define MAIN_CPP_CATALOGINDIVIDUAL_H

#include <iostream>
#include "Examen.h"
#include "ExamenFinal.h"
#include "Partial.h"
#include "Quiz.h"

template <class t> class CatalogIndividual
{
private:
    t* v;
    static int nr;
    int nr_matricol;
    int nr_examene;
public:
    CatalogIndividual(t* p = NULL, int nr_examene = 0);
    CatalogIndividual(CatalogIndividual &c);
    ~CatalogIndividual();
    static int get_nr_cataloage();
    int get_nr_examene() const;
    t get_examen(int i) const;
    CatalogIndividual& operator+=(t &examen);
    friend istream& operator>>(istream& in, CatalogIndividual<t> &p){
        cout << "Introduceti numarul de examene: ";
        in >> p.nr_examene;
        p.v = new t[p.nr_examene];
        cout << "Introduceti obiectele: \n";
        for(int i = 0; i< p.nr_examene; i++){
            in >> p.v[i];
            cout << endl;
        }
        return in;
    }
    friend ostream& operator <<(ostream& out, CatalogIndividual<t> &p){
        out << "-----------------------------------------------\n";
        out << "In catalog se gasesc urmatoarele "<< p.nr_examene<<" examene: "<<'\n';
        for(int i = 0;i< p.nr_examene; i++){
            out << p.v[i]<< "\n";
        }
        return out;
    }

};

template<class t>
int CatalogIndividual<t> ::nr = 0;
template<class t>
CatalogIndividual<t>::CatalogIndividual(t *p, int nr_examene) {
    nr++;
    this-> nr_matricol = nr;
    this->nr_examene = nr_examene;
    v = new t[nr_examene];
    for(int i = 0; i< nr_examene; i++){
        v[i] = p[i];
    }
}
template<class t>
CatalogIndividual<t>::CatalogIndividual(CatalogIndividual<t> &c) {
    nr_examene = c.nr_examene;
    nr_matricol = c.nr_matricol;
    delete[] v;
    v = new t[nr_examene];
    for(int i = 0; i< nr_examene; i++){
        v[i] = c.v[i];
    }
}
template<class t>
CatalogIndividual<t>::~CatalogIndividual() {
    delete [] v;
}
template<class t>
int CatalogIndividual<t>::get_nr_cataloage() {
    return CatalogIndividual<t>::nr;
}

template<class t>
int CatalogIndividual<t>::get_nr_examene() const {
    return this->nr_examene;
}
template<class t>
t CatalogIndividual<t>::get_examen(int i) const {
    return this->v[i];
}
template<class t>
CatalogIndividual<t>& CatalogIndividual<t>::operator+=(t &examen) {
    this->nr_examene++;
    t *aux = new t[nr_examene-1];
    for(int i = 0; i < nr_examene-1; i++){
        aux[i] = v[i];
    }
    delete[] v;
    this->v = new t[nr_examene];
    for(int i = 0; i< nr_examene-1; i++)
        v[i] = aux[i];
    delete [] aux;
    this->v[nr_examene-1] = examen;
    return *this;
}


template <> class CatalogIndividual <Quiz>
{
private:
    Quiz* v;
    static int nr;
    static int nr_persoane_cu_2_quizuri;
    int nr_matricol;
    int nr_examene;
public:
    CatalogIndividual(Quiz* t = NULL, int nr_examene  = 0);
    ~CatalogIndividual();
    int get_nr_examene() const;
    static int get_nr_persoane_cu_2_quizuri();
    Quiz get_examen(int i) const;
    CatalogIndividual& operator+=(Quiz &examen);
    friend istream& operator>>(istream& in, CatalogIndividual<Quiz> &p){
        cout << "Introduceti numarul de quiz-uri: ";
        in >> p.nr_examene;
        p.v = new Quiz[p.nr_examene];
        cout << "Introduceti obiectele: \n";
        for(int i = 0; i< p.nr_examene; i++){
            in >> p.v[i];
            cout << endl;
        }
        return in;
    }
    friend ostream& operator <<(ostream& out, CatalogIndividual<Quiz> &p){
        out << "-----------------------------------------------\n";
        out << "In catalog se gasesc urmatoarele "<< p.nr_examene<<" quiz-uri: "<<'\n';
        for(int i = 0;i< p.nr_examene; i++){
            out << p.v[i]<< "\n";
        }
        return out;
    }
};
int CatalogIndividual<Quiz> ::nr = 0;
int CatalogIndividual<Quiz> ::nr_persoane_cu_2_quizuri = 0;

CatalogIndividual<Quiz>::CatalogIndividual(Quiz *t, int nr_examene) {
    CatalogIndividual<Quiz>::nr++;
    this->nr_matricol = nr;
    this->nr_examene = nr_examene;
    this->v = new Quiz[nr_examene];
    for(int i = 0; i< nr_examene; i++)
        v[i] = t[i];
    if(nr_examene >=2)
        CatalogIndividual<Quiz>::nr_persoane_cu_2_quizuri++;
}
CatalogIndividual<Quiz>::~CatalogIndividual() {
    delete[] v;
}
int CatalogIndividual<Quiz>::get_nr_examene() const {
    return this->nr_examene;
}
int CatalogIndividual<Quiz>::get_nr_persoane_cu_2_quizuri() {
    return CatalogIndividual<Quiz>::nr_persoane_cu_2_quizuri;
}
Quiz CatalogIndividual<Quiz>::get_examen(int i) const {
    return v[i];
}
CatalogIndividual<Quiz>& CatalogIndividual<Quiz>::operator+=(Quiz &examen) {
    this->nr_examene++;
    Quiz *aux = new Quiz[nr_examene-1];
    for(int i = 0; i < nr_examene-1; i++){
        aux[i] = v[i];
    }
    delete[] v;
    this->v = new Quiz[nr_examene];
    for(int i = 0; i< nr_examene-1; i++)
        v[i] = aux[i];
    delete [] aux;
    this->v[nr_examene-1] = examen;
    return *this;
}



#endif //MAIN_CPP_CATALOGINDIVIDUAL_H
