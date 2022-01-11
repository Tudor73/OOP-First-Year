#ifndef OOP_FIRST_YEAR_MULTIME_DINAMICA_H
#define OOP_FIRST_YEAR_MULTIME_DINAMICA_H
#include <iostream>
#include <stdlib.h>


class Multime_dinamic{
private:
    Node *first;
    int nr_elemente;
public:
    Multime_dinamic();
    Multime_dinamic(Multime_dinamic&, int);
    ~Multime_dinamic();
    Node* get_head();
    int get_size();
    void add_value(int);
    void citire(istream &in);
    void afisare(ostream& out);
    void vector_to_multime(int v[], int n);
    Multime_dinamic& operator=(Multime_dinamic &lista);
    void memorare_n_obiecte();
    friend istream& operator>>(istream& in, Multime_dinamic& lista);
    friend ostream& operator<<(ostream &out, Multime_dinamic& lista);
    friend Multime_dinamic& operator+(Multime_dinamic &lista1, Multime_dinamic &lista2);
    friend Multime_dinamic& operator*(Multime_dinamic &lista1, Multime_dinamic &lista2);
    friend Multime_dinamic& operator/(Multime_dinamic &lista1, Multime_dinamic &lista2);

};
#endif //OOP_FIRST_YEAR_MULTIME_DINAMICA_H
