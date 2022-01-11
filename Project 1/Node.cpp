#include "Node.h"

Node::Node(int value = 0, Node* next = NULL)
{
    this->value = value;
    this->next = next;
}

Node::Node(Node &cpy){
    this->value=cpy.value;
    this->next=cpy.next;
}

