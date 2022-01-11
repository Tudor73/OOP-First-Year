#include <iostream>
#include <stdlib.h>
#include "Multime_dinamica.h"
#include "Node.h"
using namespace std;

void meniu_output()
{
    cout <<"\n Nume Prenume Grupa - Proiect - Nume proiect: \n";
    cout <<"\n\t\t MENIU:";
    cout <<"\n===========================================\n";
    cout <<"\n";
    cout << "1. Citirea, memorarea si afisarea unui obiect"<<endl;
    cout << "2. Reuniunea a doua multimi "<<endl;
    cout << "3. Intersectia a doua multimi "<<endl;
    cout << "4. Diferenta a doua multimi "<<endl;
    cout << "5. Transformarea unui vector in multime"<<endl;
    cout << "6. Citirea, memorarea si afisarea a n obiecte"<<endl;
    cout << "0. Iesire"<<endl;
}

void menu()
{
    int option ;
    option = 0;
    do {
        meniu_output();
        cout << "\n Introduceti numarul actiunii: ";
        cin>>option;
        if(option == 1){

            Multime_dinamic l1;
            cin>>l1;
            cout << l1;
        }
        else if(option == 2){
            Multime_dinamic l1, l2, l3;
            cout << "Prima multime"<<endl;
            cin>>l1;
            cout << "A doua multime"<<endl;
            cin>>l2;
            l3 = l1 + l2;
            cout << l3;
        }
        else if(option == 3){
            Multime_dinamic l1, l2, l3;
            cout << "Prima multime"<<endl;
            cin>>l1;
            cout << "A doua multime"<<endl;
            cin>>l2;
            l3 = l1 * l2;
            cout << l3;
        }
        else if(option == 4){
            Multime_dinamic l1, l2, l3;
            cout << "Prima multime"<<endl;
            cin >> l1;
            cout << "A doua multime"<<endl;
            cin>>l2;
            l3 = l1/l2;
            cout << l3;
        }
        else if(option == 5){
            int n;
            cout << "Numarul de elemente din vector: ";
            cin >> n;
            int v[n];
            cout << "Elementele din vector: ";
            for(int i = 0; i< n ;i++){
                cin>>v[i];
            }
            Multime_dinamic l1;
            l1.vector_to_multime(v,n);
        }
        else if(option == 6){
            Multime_dinamic l1;
            l1.memorare_n_obiecte();
        }
        else if(option<0 || option > 6)
            cout << "Selectie invalida";
        cout <<endl;
        system("pause");
        system("cls");
    }while(option != 0);
}
int main()
{
    menu();
    return 0;
}
