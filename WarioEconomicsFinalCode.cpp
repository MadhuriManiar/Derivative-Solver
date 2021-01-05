//Madhuri Maniar
//MVM190002
#include "Node.h"
#include "LList.h"
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

void getDerivitive(Node*, int, int, int, int);

int main()
{
    Node newnode;
    string filename, outcoef, incoef, term, exp, Trig, numer = "0", denomen="0";
    int power, ocoef, icoef, begterm = 0, endterm, var, newvar, open, close, num, den;
    bool trig, frac;
    //prompt user for name of input file
    cout<< "Enter name of the input file"<<endl;
    getline(cin, filename);
    ifstream infile(filename);
    ofstream outfile("derive.txt", ios::out);
    //open file
    if (infile.fail())
        cout<< "File does not exist. "<<endl;
    if (infile) {
        string line, term1, term2;
        //parse equations
        while (getline(infile, line)) {
            LList list = LList();
            if (!line.find(' '))
            {
                //find each term of the polynomial
                term = line;
                for (int i = 0; i < (int)term.length(); ++i)
                {
                    //parse each term and assign values
                    if (term.find('x'))
                    {
                        if (term[i] == 'x')
                        {
                            outcoef = term.substr(0, i);
                            if (term[i + 1] == '^') {
                                exp = term.substr(i + 2);
                            } else
                                exp = "1";
                            ocoef = stoi(outcoef);
                            power = stoi(exp);
                        }
                    }
                    else{
                        power = 0;
                    }
                }
            }
            //find all the terms
            if (line.find(" +")||line.find(" -"))
            {
                for (int i = 0; i <= (int)line.length(); i++) {
                    if (line.substr(i,2) == "+ " || line.substr(i, 2)=="- " || line[i]=='\0')
                    {
                        icoef = 0;
                        ocoef = 0;
                        power = 0;
                        Trig = "";
                        trig = false;
                        frac = false;
                        numer = "0";
                        denomen = "0";
                        endterm = i-1;
                        if (line[i]=='\0')
                            term = line.substr(begterm, endterm-begterm+1);
                        else
                            term = line.substr(begterm, endterm - begterm);
                        for (int j = 0; j < (int)term.length(); j++)
                        {
                            if (term[0]=='x')
                                ocoef = 1;
                            if (term[0]=='-' && term[1] == 'x')
                                ocoef = -1;
                            //find fractions
                            if (term[j]=='/')
                            {
                                ocoef = 1;
                                frac = true;
                                open = (int)term.find('(');
                                close = (int)term.find(')');
                                numer = term.substr(open+1, j-open-1);
                                denomen = term.substr(j+1, close-j-1);
                            }
                            //find exponents
                            if (term[j]=='x')
                            {
                                if (term[j+1]=='^')
                                    exp = term.substr(j+2);
                                if (term[j+1]!='^')
                                    exp = "1";
                                power = stoi(exp);
                            }
                            //find trig values
                            if ((term[j]=='t'||(term[j]=='s'&&term[j+2]=='n')||term[j]=='c'))
                            {
                                trig = true;
                                var = j;
                                if (var==0)
                                {
                                    outcoef="1";
                                    ocoef = stoi(outcoef);
                                }
                                else if (term[0] == '+' && !frac) {
                                    outcoef = term.substr(2, var - 2);
                                    if (outcoef.length() == 0)
                                        outcoef = "1";
                                    ocoef = stoi(outcoef);
                                } else if (term[0] == '-'&& !frac && term[1]==' ') {
                                    outcoef = term.substr(2, var - 2);
                                    if (outcoef.length() == 0)
                                        outcoef = "1";
                                    ocoef = stoi(outcoef)*-1;
                                }
                                else if (term[0]=='-' && !frac && term[1] != ' '){
                                    outcoef = term.substr(1, var - 1);
                                    ocoef = stoi(outcoef)*-1;
                                }
                                else if (!frac){
                                    outcoef = term.substr(0, var);
                                    ocoef = stoi(outcoef);
                                }
                            }
                            //find inner coefficients
                            else if (term[j]=='n'||(term[j]=='s' && term[j-2]=='c'))
                            {
                                if (term[j+6]=='x')
                                    newvar = j+6;
                                if (term[j+5]=='x')
                                    newvar = j+5;
                                if (term[j+4]=='x')
                                    newvar=j+4;
                                if (term[j+3]=='x')
                                    newvar = j+3;
                                if (term[j+2]=='x')
                                    incoef = "1";
                                else
                                    incoef = term.substr(j+2, newvar-j-2);
                                icoef = stoi(incoef);
                            }
                            //find outer coefficients
                            else if (term[j]=='x'&& !trig && !frac)
                            {
                                var = j;
                                if (var == 0) {
                                    outcoef = "1";
                                    ocoef = stoi(outcoef);
                                }
                                else if (term[0]=='-'&&term[1]!=' '){
                                    outcoef = term.substr(1, var-1);
                                    if (outcoef.length()==0)
                                        outcoef = "1";
                                    ocoef = stoi(outcoef)*-1;
                                }
                                else if (term[0] == '+') {
                                    outcoef = term.substr(2, var - 2);
                                    if (outcoef.length() == 0)
                                        outcoef = "1";
                                    ocoef = stoi(outcoef);
                                } else if (term[0] == '-') {
                                    outcoef = term.substr(2, var - 2);
                                    if (outcoef.length() == 0)
                                        outcoef = "1";
                                    ocoef = stoi(outcoef)*-1;
                                } else {
                                    outcoef = term.substr(0, var);
                                    if (!frac)
                                        ocoef = stoi(outcoef);
                                }
                            }
                            //assign trig values
                            if (trig)
                            {
                                if (term.substr(j, 3)=="sin")
                                    Trig = "sin";
                                if (term.substr(j, 3)=="tan")
                                    Trig = "tan";
                                if (term.substr(j, 3)=="cos")
                                    Trig = "cos";
                                power = 1;
                            }

                        }
                        if (power == 0 && ocoef != 1)
                        {
                            continue;
                        }
                        if (term[0]=='-')
                            num = stoi(numer)*-1;
                        else
                            num = stoi(numer);
                        den = stoi(denomen);
                        if (trig)
                            icoef = stoi(incoef);
                        //create new node for each term
                        Node *node = new Node(ocoef, icoef, power, Trig, num, den);
                        //find derivitives
                        if (node->getOuter()!=0 || node->getExp()!=0)
                            getDerivitive(node, ocoef, power, num, den);
                        list>>node;
                        begterm += (int)term.length()+1;
                    }
                }
                //sort and print out new polynomial
                list.sort();
                cout<<list;
                outfile<<list;
                list = LList();
                begterm = 0;
            }
        }
    }
}

void getDerivitive(Node *newnode, int outer, int expon, int top, int bot)
{
    //if a fraction is in the term
    if (newnode->getNum()!=0)
    {
        if (newnode->getTrig()!="")
            top = newnode->getInner()*top;
        else
            top = top*expon;
        int i = 1;
            while (i < 10)
            {
                if(bot % i == 0 && top % i == 0)
                {
                    bot = bot / i;
                    top = top / i;

                    if (top % bot != 0)
                        i++;
                    if (top % bot == 0)
                        break;
                }
                else
                    i++;
            }
        if (top % bot == 0)
        {
            newnode->setNum(top/bot);
            newnode->setDenom(1);
        }
        else {
            newnode->setNum(top);
            newnode->setDenom(bot);
        }
        newnode->setExp(expon-1);
    }
    //no fraction in term
    if (newnode->getTrig()=="" && newnode->getNum()==0)
    {
        if (expon == 0)
            newnode->setOuter(1*outer);
        else {
            newnode->setOuter(outer * expon);
            newnode->setExp(expon - 1);
        }
    }
    else if (newnode->getTrig()!=""){
        newnode->setOuter(newnode->getInner()*newnode->getOuter());
        if (newnode->getTrig() == "sin")
        {
            newnode->setTrig("cos");
        }
        else if (newnode->getTrig() == "cos")
        {
            newnode->setTrig("sin");
            if (newnode->getNum()!=0)
                newnode->setNum(newnode->getNum()*-1);
            else
                newnode->setOuter(newnode->getOuter()*-1);

        }
        else if (newnode->getTrig() == "tan")
        {
            newnode->setTrig("sec");
            newnode->setExp(-2);
        }
    }

}