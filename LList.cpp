//Madhuri Maniar
//MVM190002
#include "LList.h"
#include <iostream>



LList::LList()
{
    //default constructor
    head = nullptr;
}

LList::LList(Node *list)
{
    //copy constructor
    head = new Node();
    Node *ptr = head;
    while (list != nullptr)
    {
        Node *newnode = new Node();
        ptr->setNext(newnode);
        ptr->setOuter(list->getOuter());
        ptr->setExp(list->getExp());
        ptr->setNum(list->getNum());
        ptr->setDenom(list->getDenom());
        ptr->setInner(list->getInner());
        ptr->setTrig(list->getTrig());
        if (list->getNext()== nullptr)
            ptr->setNext(nullptr);
        list = list->getNext();
        ptr = ptr->getNext();
    }

}

LList::~LList()
{
    //destructor
    Node *temp = head;
    Node *next;
    while (temp != nullptr)
    {
        next = temp->getNext();
        delete temp;
        temp = next;
    }

}


void LList::sort()
{
    //to sort the polynomials in descending order based on exponent
    bool Swap = false;
    Node *sort = head;
    Node *index;
    Node *curr;
    Node *prev;
    int count = 0;

    while (sort != nullptr){
        sort = sort->getNext();
        count++;
    }
    sort = head;
    for (int i = 0; i < count-1; i++)
    {
        prev = sort;
        for (int j = 0; j < count-i-1; j++)
        {
            curr = sort;
            index = curr->getNext();
            if (index->getTrig()=="" && curr->getTrig()=="") {
                if ((curr->getExp() < index->getExp())) {
                    Swap = true;
                    sort = LList::swap(curr, index, prev);
                }
            }
            if (j==0 && Swap)
                head = index;
            prev = sort;
            sort = sort->getNext();
        }
        if (!Swap)
            break;
        Swap = false;
        sort = head;
    }
}

Node* LList::swap(Node *pos, Node *pos1, Node *pos2)
{
    //swaps nodes
    Node *temp = pos1->getNext();
    pos1->setNext(pos);
    pos2->setNext(pos1);
    pos->setNext(temp);
    return pos1;

}


void LList::setHead(Node *n)
{
    //sets the head
    head = n;
}

Node *LList::getHead()
{
    //returns the head
    return head;
}

Node* LList::operator[](int index) const
{
    //returns the reference of node
    Node *sort = head;
    int count = 0;
    while (sort != nullptr){
        if (index == count)
            return sort;
        sort = sort->getNext();
        count++;
    }
    return nullptr;

}

std::ostream& operator<<(std::ostream &ofstream, LList const &list)
{
    //prints out entire linked list
    char sign;
    int i = 0;
    while (true)
    {
        sign = '+';
        Node *curr = list[i];
        if (curr == nullptr)
            break;
        else {
            if (i == 0) {
                if (curr->getOuter() < 0 || curr->getNum() < 0)
                    ofstream << "-" << *curr<<" ";
                else
                    ofstream << *curr<<" ";
            } else {
                if (curr->getOuter() < 0 || curr->getNum() < 0) {
                    sign = '-';
                }
                if (curr->getNext()== nullptr)
                    ofstream << sign << " " << *curr<<std::endl;
                else
                    ofstream << sign << " " << *curr<<" ";
            }
            i++;
        }
    }
    return ofstream;
}


void LList::operator>>(Node *node)
{
    //adds node to the beggining of the linked list
    if(node != nullptr)
    {
        if (node->getTrig()!="")
        {
            if (head == nullptr)
            {
                setHead(node);
            }
            else {
                Node *curr = head;
                while (curr->getNext() != nullptr)
                {
                    curr = curr->getNext();
                }
                curr->setNext(node);
            }
        }
        else {
            node->setNext(head);
            setHead(node);
        }

    }
}



