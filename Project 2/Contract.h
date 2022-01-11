#ifndef OOP_FIRST_YEAR_CONTRACT_H
#define OOP_FIRST_YEAR_CONTRACT_H


class Contract{
protected:
    int nrContract;
    int an;
    string nume;
    string furnizor;
    int valoare;
    static int nr;
public:
    Contract(int nrContract = 0, int an = 0, string nume = "", string furnizor = "", int valoare = 0);
    Contract(Contract &c);
    virtual ~Contract();
    virtual void citire(istream& in);
    virtual void afisare(ostream& out);
    friend istream& operator>>(istream &in, Contract &c);
    friend ostream& operator<<(ostream &out, Contract &c);
    int get_valoare();
    int get_nrContract();
    static int nr_contracte();
    Contract& operator=(Contract c);
};

#endif //OOP_FIRST_YEAR_CONTRACT_H
