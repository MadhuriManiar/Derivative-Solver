//Madhuri Maniar
//MVM190002
#include "Node.h"
#include <iostream>
#include <cmath>


Node::Node()
{
    //default constructor
    outer = 0;
    inner = 0;
    num = 0;
    denom = 0;
    exp = 0;
    trig = "";
    next = nullptr;
}

Node::Node(int out, int in, int expo, std::string tri, int top, int bot)
{
    //assigns values
    outer = out;
    exp = expo;
    inner = in;
    trig = tri;
    num = top;
    denom = bot;
}

void Node::setOuter(int out)
{
    //sets outer coefficient
    outer = out;
}

void Node::setInner(int in)
{
    //sets inner coefficient if trig exists
    inner = in;
}

void Node::setExp(int expo)
{
    //sets exponent
    exp = expo;
}

void Node::setTrig(std::string trigo)
{
    //sets trig
    trig = trigo;
}

int Node::getOuter()const
{
    //returns outer coefficient
    return outer;
}

int Node::getInner()
{
    //returns inner coefficient if trig exists
    return inner;
}

int Node::getExp()const
{
    //returns exponent
    return exp;
}

std::string Node::getTrig()
{
    //returns trig
    return trig;
}

Node* Node::getNext()
{
    //returns next node
    return next;
}

int Node::getNum()
{
    //returns numerator in fraction
    return num;
}

int Node::getDenom()
{
    //returns denominator in fraction
    return denom;
}

void Node::setNext(Node *n)
{
    //sets next node
    next = n;
}

void Node::setNum(int n)
{
    //sets numerator in fraction
    num = n;
}

void Node::setDenom(int d)
{
    //sets denominator in fraction
    denom = d;
}

std::ostream& operator<<(std::ostream &ofstream, Node node)
{
    //prints out node

    //if there is a fraction in term
    if (node.getNum()!=0)
    {
        if (node.getInner()==1)
        {
            ofstream<<"("<<abs(node.getNum())<<"/"<<node.getDenom()<<")"<<node.getTrig()<<" "<<"x";
            return ofstream;
        }
        if (node.getNum()==1 && node.getDenom()==1)
        {
            ofstream<<node.getTrig()<<" "<<node.getInner()<<"x";
            return ofstream;
        }
        if (node.getNum()==-1 && node.getDenom()==1)
        {
            ofstream<<node.getTrig()<<" "<<node.getInner()<<"x";
            return ofstream;
        }
        if (node.getDenom()!=1) {
            if (node.getTrig()!=""){
                ofstream<<"("<<abs(node.getNum())<<"/"<<node.getDenom()<<")"<<node.getTrig()<<" "<<node.getInner()<<"x";
                return ofstream;
                }
            if (node.getExp()==1)
                ofstream<<"("<<abs(node.getNum())<<"/"<<node.getDenom()<<")"<<"x";
            else
                ofstream << "(" << abs(node.getNum()) << "/" << node.getDenom() << ")" << "x^" << node.getExp() ;
        }
        if (node.getDenom()==1) {
            if (node.getTrig()!="") {
                ofstream << abs(node.getNum()) << node.getTrig() << " " << node.getInner() << "x" ;
                return ofstream;
            }
            if (node.getExp()==1)
                ofstream<<node.getNum()<<"x";
            else
                ofstream << node.getNum() << "x^" << node.getExp();
        }

        return ofstream;
    }
    //if trig exists in the term
    if(node.getTrig()!="")
    {
        if (node.getOuter()==1 || node.getOuter() == -1)
        {
            if (node.getOuter()==1) {
                if (node.getInner() == 1)
                {
                    if (node.getTrig()=="sec")
                    {
                        ofstream<<node.getTrig()<<"^2"<<" "<<"x";
                        return ofstream;
                    }
                    ofstream << node.getTrig() << " " << "x" ;
                }
                if (node.getInner() != 1)
                {
                    if (node.getTrig()=="sec")
                    {
                        ofstream<<node.getTrig()<<"^2"<<" "<<node.getInner()<<"x";
                        return ofstream;
                    }
                    ofstream << node.getTrig() << " " << node.getInner() << "x" ;
                    return ofstream;
                }
            }
            if (node.getOuter()==-1)
            {
                if (node.getInner() == 1)
                {
                    if (node.getTrig()=="sec")
                    {
                        ofstream<<node.getTrig()<<"^2"<<" "<<"x";
                        return ofstream;
                    }
                    ofstream <<node.getTrig() << " " << "x" ;
                }
                if (node.getInner() != 1)
                {
                    if (node.getTrig()=="sec")
                    {
                        ofstream<<"-"<<node.getTrig()<<"^2"<<" "<<node.getInner()<<"x";
                        return ofstream;
                    }
                    ofstream << "-"<<node.getTrig() << " " << node.getInner() << "x" ;
                }
            }
            return ofstream;
        }
        else
        {
            if (node.getInner()!=1) {
                if (node.getTrig() == "sec") {
                    ofstream << abs(node.getOuter()) << node.getTrig() << "^2" <<" "<< node.getInner() << "x";
                    return ofstream;
                }
            }
            if (node.getInner()==1){
                if (node.getTrig() == "sec") {
                    ofstream << abs(node.getOuter()) << node.getTrig() << "^2" <<" "<< "x";
                    return ofstream;
                }
            }
        }
        if (node.getInner()==1)
        {
            ofstream<<abs(node.getOuter())<<node.getTrig()<<" "<<"x";
        }
        if (node.getInner()!=1)
        {
            ofstream << abs(node.getOuter()) << node.getTrig() << " "<<node.getInner() << "x";
        }
        return ofstream;
    }
    //no trig and no fraction in term
    if (node.getExp()==0 && node.getOuter()==0){
        ofstream<<"1";
        return ofstream;
    }
    if (node.getExp()==0)
    {
        ofstream<<abs(node.getOuter());
        return ofstream;
    }
    if (node.getOuter()==1)
    {
        ofstream<<"x^"<<node.getExp();
        return ofstream;
    }
    if (node.getInner()==0){
        if (node.getExp() == 0) {
            ofstream << abs(node.getOuter()) << node.getTrig();
        }
        else if (node.getExp() == 1)
        {
            ofstream << abs(node.getOuter())  << "x" ;
        }
        else
            ofstream << abs(node.getOuter()) << node.getTrig() <<"x^" << node.getExp();
        return ofstream;
    }
    if (node.getOuter()!=0 && node.getExp()!=0)
    {
        ofstream<<node.getOuter()<<"x^"<<node.getExp();
            return ofstream;
    }
    return ofstream;
}







