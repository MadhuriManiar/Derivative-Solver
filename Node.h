//Madhuri Maniar
//MVM190002
#include <iostream>
#ifndef NODE_H
#define NODE_H


class Node
{
private:
    //variables
    int outer;
    int inner;
    int num;
    int denom;
    int exp;
    std::string trig;
    Node *next;
public:
    Node();
    Node(int, int, int, std::string, int, int);
    friend std::ostream& operator<<(std::ostream &, Node);
    //accessors
    int getOuter()const;
    int getInner();
    int getNum();
    int getDenom();
    int getExp()const;
    std::string getTrig();
    Node* getNext();

    //mutators
    void setOuter(int);
    void setInner(int);
    void setExp(int);
    void setTrig(std::string);
    void setNum(int);
    void setDenom(int);
    void setNext(Node*);
};



#endif