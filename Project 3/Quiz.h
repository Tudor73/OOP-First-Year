#ifndef MAIN_CPP_QUIZ_H
#define MAIN_CPP_QUIZ_H
#include <iostream>
#include "Examen.h"


class Quiz: public Examen{
private:
    int nr_itemi_grila;
public:
    Quiz(string = "", int = 0, string = "", int = 0);
    void citire(istream&);
    void afisare(ostream&);
    Quiz& operator=(Quiz &q);
    friend istream& operator>>(istream&, Quiz& );
    friend ostream& operator<<(ostream&, Quiz& );
};

#endif //MAIN_CPP_QUIZ_H
