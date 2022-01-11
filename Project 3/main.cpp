#include <iostream>
#include <unordered_map>
#include <string.h>
#include <stdlib.h>
#include <list>
#include "Examen.h"
#include "ExamenFinal.h"
#include "Partial.h"
#include "Quiz.h"
#include "CatalogIndividual.h"
using namespace std;


void tip(Examen *&e, int &i,list<Examen*> &l ){
    string s;
    cout << "Introduceti tipul examenului "<< i+ 1<<" (partial/final/quiz): ";
    cin >> s;
    try {
        if (s == "partial") {
            e = new Partial;
            cin >> *e;
            l.push_back(*&e);
        } else if (s == "final") {
            e = new ExamenFinal;
            cin >> *e;
            l.push_back(*&e);
        } else if (s == "quiz") {
            e = new Quiz;
            cin >> *e;
            l.push_back(*&e);
        }
        else
            throw 1;
    }
    catch(bad_alloc var){
        cout << "Alocation Failure"<<endl;
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout << "Nu ati introdus un examen valid.";
    }

}
void menu_output()
{
    cout<<"\n Minciunescu Tudor Grupa 134 Proiect 3-Tema 3 : \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste informatii despre n examene "<<endl;
    cout<<"2. Contorizare examene citite "<<endl;
    cout<<"3. Catalog Individual -- TEMPLATE(partial) "<<endl;
    cout<<"4. Catalog Individual -- TEMPLATE(examen final)"<<endl;
    cout<<"5. Catalog Individual -- TEMPLATE(quiz)"<<endl;
    cout<<"6. Afisarea numarului de persoane cu mai mult de 2 quiz-uri"<<endl;
    cout<<"7. Citirea a n elevi si afisarea elevilor care nu au luat examenul "<<endl;
    cout <<"0. Iesire";
    cout<<endl;
}
void menu()
{
    int option;
    list<Examen*> lista;
    unordered_map<int, list<Elev>> map;
    Examen** v;
    int n = 0;
    do
    {
        menu_output();
        cout << "Introduceti numarul actiunii: ";
        cin >> option;
        if(option == 1){
            cout << "Introduceti numarul de obiecte citite: ";
            cin >> n;
            v = new Examen*[n];
            if(n > 0)
            {
                for(int i =0; i< n; i++)
                    tip(v[i],i,lista);
                cout << "\n Afisam examenele citite:\n";
                list<Examen*>::iterator i;
                for(i = lista.begin(); i != lista.end(); ++i) {
                    cout << **i << endl;
                    cout << "----------------------------\n";
                }
            }
            else
                cout << "Numarul introdus trebuie sa fie mai mare ca 0\n";
        }
        else if(option == 2)
        {
            int N_partial, N_final, N_quiz;
            N_partial = N_final = N_quiz = 0;
            if(n > 0)
            {
                for(int i = 0; i< n; i++)
                {
                    Partial *e1 = dynamic_cast<Partial*>(v[i]);
                    ExamenFinal *e2 = dynamic_cast<ExamenFinal*>(v[i]);
                    Quiz *e3 = dynamic_cast<Quiz*>(v[i]);
                    if (e1)
                        N_partial++;
                    if(e2)
                        N_final++;
                    if(e3)
                        N_quiz++;
                }
                cout << "Numarul de partiale: "<< N_partial <<endl;
                cout << "Numarul de examene finale: "<< N_final << endl;
                cout << "Numarul de quiz-uri: "<< N_quiz<<endl;
            }
            else
                cout << "Nu s-au citit examene. Reveniti la actiunea 1"<<endl;
        }
        if(option == 3)
        {
            CatalogIndividual<Partial> partiale;
            cin >> partiale;
            cout << partiale;
        }
        if(option == 4)
        {
            CatalogIndividual<ExamenFinal> examene_finale;
            cin >> examene_finale;
            cout << examene_finale;
        }
        if(option == 5)
        {
            CatalogIndividual<Quiz> quizuri;
            cin >> quizuri;
            cout << quizuri;
        }
        if(option == 6)
        {
            cout << CatalogIndividual<Quiz>::get_nr_persoane_cu_2_quizuri();
        }
        if(option == 7)
        {
            if( n == 0)
            {
                cout << "Nu ati introdus examenele. Reveniti la actiunea 1"<<endl;
            }
            else {
                int m;
                cout << "Introduceti numarul de elevi: ";
                cin >> m;
                if (m > 0) {
                    cout << "Intoduceti elevii: "<< endl;
                    for (int i = 0; i < m; i++) {
                        Elev e;
                        cin >> e;
                        int id_elev = e.get_id_examen(); /// the id of the exam from the ELev object
                        for(int j = 0; j< n; j++)
                        {
                            int id_examen = v[j]->get_id_examen();/// the id of the exam from the Examen object
                            if(map.find(id_examen) == map.end())
                                map[id_examen] = list<Elev>();
                            if(id_examen == id_elev && v[i]->get_nota() < 5){
                                map[id_examen].push_back(e);
                            }
                        }
                    }
                    for(auto i: map){
                        cout << i.first<< ": ";
                        list<Elev> copie_lista = i.second;
                        if(copie_lista.empty()){
                            cout << "Nu exista elevi care au picat acest examenul "<<endl;
                        }
                        else {
                            for (auto j : copie_lista) {
                                cout << j << " ";
                            }
                            cout << endl<<endl;
                        }
                    }
                }
                else
                    cout << "Numarul de elevi trebuie sa fie pozitiv "<<endl;
            }
        }
        if(option == 0)
            cout << "\nEXIT\n\n";
        if(option < 0 || option > 7)
        {
            cout << "\n Selectie invalida \n";
        }
        cout << endl;
        system("pause");
        system("cls");
    }
    while(option != 0);
}
int main() {

    menu();
    return 0;
}


