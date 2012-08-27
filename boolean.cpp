/* Written by S Krishna Savant (100070056) for CS213(M) Assignment
 *
 * Data Structure to implement Boolean Expressions
 * Construct a Boolean Exp from literals and define basic operations
 * BooleanExp is in cnf form : A vector of vectors of Literals
 * A vector of literals is a clause (Interpreted as disjunction of literals)
 * A vector of clauses is Interpreted as conjunction of clauses
 *
 * Submission done in haste (Sorry)
 * For further improvements to code done after submission please refer to https://github.com/savvy2020/cs213/
 */
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<sstream>

class Literal  {
    public:
        std::string name; //Name of the literal
        bool state; //State : true if positive literal false otherwise
        Literal();
        Literal(std::string);
        Literal(std::string,bool);
        void operator=(Literal);
        //Variable(bool);no name: give random name : TODO
};

class BooleanExp {
    //Variables: public private //cnf form : vector of vector of Literals Conjuction of Disjunctions
    public:
        std::vector<std::vector<Literal> > cnfform;
        BooleanExp();
        BooleanExp(Literal);
        BooleanExp(std::string); //To write
        bool Statifiable(); //To write
        bool Tautology(); //To write
        bool Contradiction(); //To write
};

template<typename T>
std::string itostr(T val){
  std::stringstream s;
  s<<val;
  return s.str();
}

Literal::Literal(){
    Literal("x"+itostr(rand()%1000),true);
}

Literal::Literal(std::string namein,bool valuein){
    name=namein;
    state=valuein;
}

Literal::Literal(std::string namestr){
    Literal(namestr,true);
}

void Literal::operator=(Literal l){
            name=l.name;
            state=l.state;
}

std::vector<Literal> vector(Literal l){
    std::vector<Literal> lv;
    lv.push_back(l);
    return lv;
}

BooleanExp::BooleanExp(){
}

BooleanExp::BooleanExp(Literal l){
    std::vector<Literal> x;
    x.push_back(l);
    cnfform.push_back(x);
}

Literal Not(Literal l){
    return Literal(l.name,!l.state);

}

BooleanExp And(Literal l1,Literal l2){
    BooleanExp x=BooleanExp();
    x.cnfform.push_back(vector(l1));
    x.cnfform.push_back(vector(l2));
    return x;
}

BooleanExp And(BooleanExp b, Literal l){
    BooleanExp x=BooleanExp();
    x.cnfform=b.cnfform;
    x.cnfform.push_back(vector(l));
    return x;
}

BooleanExp And(BooleanExp b1, BooleanExp b2){
    BooleanExp x=BooleanExp();
    x.cnfform=b1.cnfform;
    for(std::vector<std::vector<Literal> >::iterator i=b2.cnfform.begin();i!=b2.cnfform.end(); ++i){
        x.cnfform.push_back(*i);
    }
    return x;
}

BooleanExp Or(Literal l1,Literal l2){
    BooleanExp x=BooleanExp();
    x.cnfform.push_back(vector(Not(l1)));
    x.cnfform.push_back(vector(Not(l2)));
    return x;
}
int main(){
   //Testing
    int n=4;
    std::vector<Literal> vars(n,Literal());
    for(int i=0; i<n; ++i){
        vars[i]=Literal("x"+itostr(i));
    }
    BooleanExp exp=BooleanExp();
    exp=And(vars[0],vars[1]);
    return 0;
}
