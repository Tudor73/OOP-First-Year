#include <iostream>
#include <stdlib.h>
#include "Contract.h"
#include "ContractInchiriere.h"
#include "Dosar.h"
using namespace std;


void tip( Contract *&c, int i){
    string s;
    cout << "Introduceti tipul contractului "<<i+1 << " (simplu/inchiriere)";
    cin>>s;
    if(s == "simplu"){
        c = new Contract;
        cin>> *c;
    }
    else{
        c = new ContractInchiriere;
        cin>> *c;
    }
}

void memorarea_n_obiecte(){
    int n;
    cout << "Numarul de obiecte: ";
    cin>> n;
    Contract **v;
    v = new Contract*[n];
    for(int i = 0; i< n;i++){
        tip(v[i],i);
    }
    cout <<endl<< "Afisarea contractelor citite anterior: "<<endl<<endl;
    for(int i = 0; i < n; i++){
        cout << *v[i]<<endl;
        cout << "-----------------------------------"<<endl;
    }
}

void menu_output(){
    cout<<"\n Minciunescu Tudor Grupa 134 Proiect 8-Contract : \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citirea si afisarea a n obiecte de tip contract/contractInchiriere "; cout<<"\n";
    cout<<"2. Numarul total de contracte "; cout<<"\n";
    cout<<"3. Citirea si afisarea contractelor de inchiriere din dosar "; cout<<"\n";
    cout<<"4. Valoarea incasata din dosar in functie de perioada"; cout<<"\n";
    cout<<"5. Valoarea total incasata din dosar "; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
}
void menu()
{
    int option;
    option=0;
    Dosar d;
    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
           memorarea_n_obiecte();
        }
        if (option==2)
        {
           cout << Contract::nr_contracte();
        }
        if (option==3)
        {
            cin>> d;
            cout << d;
        }
        if (option==4)
        {
            d.valoare_pe_perioada();
        }
        if (option==5)
        {
            cout <<"Valoarea totala este " << d.get_valoarea_totala();
        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>5)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause");
        system("cls");
    }
    while(option!=0);
}
int main() {
    menu();
    return 0;
}
