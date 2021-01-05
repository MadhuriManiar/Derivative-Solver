//Madhuri Maniar
//MVM190002
#include <iostream>
#include "Node.h"
#ifndef LLIST_H
#define LLIST_H


class LList
{
private:
    //variables
    Node *head;
public:
    //constructors
    LList();
    LList(Node*);
    ~LList();
    void operator>>(Node*);
    friend std::ostream& operator<<(std::ostream &, LList const &);
    Node* operator[](int)const;
    //mutators
    void setHead(Node*);
    Node* swap(Node*, Node*, Node*);
    void sort();
    Node* getHead();

};

#endif