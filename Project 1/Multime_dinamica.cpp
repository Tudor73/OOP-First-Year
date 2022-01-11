#include "Multime_dinamica.h"

using namespace std;


Multime_dinamic::Multime_dinamic()
{
    first = 0;
    nr_elemente = 0;
}

Multime_dinamic::Multime_dinamic(Multime_dinamic &initial, int n)
{
    if(initial.first == 0){
        this->first = 0;
        this->nr_elemente = 0;
    }
    else{
        this->nr_elemente = n;
        first = new Node(*initial.first);
        Node *p = initial.first->next;
        Node *q = first;
        while(p){
            q->next = new Node(*p);
            p = p->next;
            q = q->next;
        }
    }
}

Multime_dinamic::~Multime_dinamic()
{
    Node *p = first;
    Node *q;
    while(p != NULL){
        q = p;
        p = p->next;
        delete q;
    }
    first = 0;
    nr_elemente = 0;
}

void Multime_dinamic::add_value(int x)
{
    Node *p = new Node(x,NULL);
    if(first == 0){
        first = p;
    }
    else{
        Node *head = first;
        while(head->next != NULL){
            head = head->next;
        }
        head->next = p;
    }
    nr_elemente++;
}

void Multime_dinamic::citire(istream& in)
{
    cout << "Numarul de elemente din multime: ";
    in>>this->nr_elemente;
    cout << "Elementele din multime: ";
    int x;
    in>>x;
    first = new Node;
    first->value = x;
    Node *coada = new Node;
    coada = first;
    for(int i =1; i< nr_elemente;i++){
        in>>x;
        Node *q = new Node;
        q->value = x;
        coada->next = q;
        coada = q;
    }
}
void Multime_dinamic::afisare(ostream& out)
{
    Node *head = first;
    while(head != NULL){
        out << head->value << " ";
        head = head->next;
    }
    out << endl;
}

istream& operator>>(istream& in, Multime_dinamic& lista)
{
    lista.citire(in);
    return in;
}

ostream&operator<<(ostream& out, Multime_dinamic& lista)
{
    lista.afisare(out);
    return out;
}

Node* Multime_dinamic::get_head()
{
    return first;
}

int Multime_dinamic::get_size()
{
    return nr_elemente;
}

void Multime_dinamic::vector_to_multime(int v[], int n)
{
    int maxim = 0;
    for(int i = 0; i< n ; i++)
    {
        if(v[i] > maxim)
            maxim = v[i];
    }
    int *a = new int[maxim];
    for(int i = 0;i<= maxim;i++)
        a[i]= 0;
    int new_vector[n];
    int nr = 0;
    for(int i = 0 ;i< n; i++)
        a[v[i]] = 1;
    for(int i = 0; i<= maxim; i++){
        if(a[i] != 0){
            new_vector[nr] = i;
            nr++;
        }
    }
    for(int i = 0; i<nr; i++)
        cout << new_vector[i] << " ";
    cout << endl;
}
void Multime_dinamic::memorare_n_obiecte()
{
    int n;
    cout << "Numarul de obiecte: ";
    cin>>n;
    Multime_dinamic* v = new Multime_dinamic[n];
    for(int i = 0;i< n; i++){
        cin >> v[i];
    }
    for(int i = 0; i< n; i++)
        cout << v[i];
}

Multime_dinamic& Multime_dinamic::operator=(Multime_dinamic& lista)
{

    this->first = new Node(*lista.first);
    this->nr_elemente = lista.nr_elemente;
}


inline Multime_dinamic& operator+(Multime_dinamic &lista1, Multime_dinamic &lista2)
{
    Node *p = lista1.first;
    Node *head = new Node;
    Node *coada = new Node;
    int nr = 0;
    while(p != NULL){
        if(nr == 0){
            head->value = p->value;
            coada = head;
            nr++;
        }
        else{
            int ok = 1;
            Node *q = new Node(*head);
            while (q != NULL){
                if(q -> value == p->value)
                    ok = 0;
                q = q->next;
            }
            if(ok == 1){
                Node *t = new Node;
                t->value = p->value;
                coada->next = t;
                coada = t;
                nr++;
            }
        }
        p = p->next;
    }
    p = lista2.first;
    while(p != NULL){
        if(nr == 0){
            head->value = p->value;
            coada = head;
            nr++;
        }
        else{
            int ok = 1;
            Node *q = new Node(*head);
            while (q != NULL){
                if(q -> value == p->value)
                    ok = 0;
                q = q->next;
            }
            if(ok == 1){
                Node *t = new Node;
                t ->value = p->value;
                coada->next = t;
                coada = t;
            }
        }
        p = p->next;
    }
    Multime_dinamic *reuniune = new Multime_dinamic;
    reuniune->first = head;
    reuniune->nr_elemente = nr;
    return *reuniune;

}

inline Multime_dinamic& operator*(Multime_dinamic& lista1, Multime_dinamic& lista2)
{
    Node *p = lista1.first;
    Node *head = new Node;
    Node *copie = new Node;
    int nr = 0;
    while(p != NULL){
        int ok = 0;
        Node *q = lista2.first;
        while(q != NULL){
            if(p->value == q-> value)
                ok = 1;
            q = q->next;
        }
        if(ok == 1){
            if(nr == 0){
                Node *q = new Node;
                q->value = p->value;
                head = q;
                copie = q;
                nr++;
            }
            else{
                Node *q = new Node;
                q->value = p->value;
                copie->next = q;
                copie = q;
                nr++;
            }
        }
        p = p->next;
    }
    Multime_dinamic *intersectie = new Multime_dinamic;
    intersectie->first = head;
    intersectie->nr_elemente = nr;
    return *intersectie;
}

inline Multime_dinamic& operator/(Multime_dinamic &lista1, Multime_dinamic &lista2)
{
    Node *p = lista1.first;
    Node *head = new Node;
    Node *copie = new Node;
    int nr = 0;
    while(p != NULL){
        int ok = 1;
        Node *q = lista2.first;
        while(q != NULL){
            if(p->value == q-> value)
                ok = 0;
            q = q->next;
        }
        if(ok == 1){
            if(nr == 0){
                Node *q = new Node;
                q->value = p->value;
                head = q;
                copie = q;
                nr++;
            }
            else{
                Node *q = new Node;
                q->value = p->value;
                copie->next = q;
                copie = q;
                nr++;
            }
        }
        p = p->next;
    }
    Multime_dinamic *diferenta = new Multime_dinamic;
    diferenta->first = head;
    diferenta->nr_elemente = nr;
    return *diferenta;
}
