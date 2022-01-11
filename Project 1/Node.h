#ifndef OOP_FIRST_YEAR_NODE_H
#define OOP_FIRST_YEAR_NODE_H


class Node {
private:
    int value;
    Node* next;
public:
    Node(int, Node*);
    Node(Node&);
    friend class Multime_dinamic;
    friend Multime_dinamic& operator+(Multime_dinamic &lista1, Multime_dinamic &lista2);
    friend Multime_dinamic& operator*(Multime_dinamic &lista1, Multime_dinamic &lista2);
    friend Multime_dinamic& operator/(Multime_dinamic &lista1, Multime_dinamic &lista2);
};



#endif //OOP_FIRST_YEAR_NODE_H
