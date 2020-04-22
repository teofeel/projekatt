#ifndef TICKET_HPP_INCLUDED
#define TICKET_HPP_INCLUDED
#include "stock.hpp"
//potvrda da smo kupili deonice, ispisuje se samo simbol i kupovna cena
class Ticket{
private:
    int num;
    int quantity;
    Stock st;
public:
    Ticket(int n, int quant,const Stock st1): st(st1)
    {
        num=n;
        quantity=quant;
    }
    Ticket(const Ticket &t1): st(t1.st)
    {
        num=t1.num;
        quantity=t1.quantity;
    }
    void setNum(int n){num=n;}
    void setQuant(int q){quantity=q;}

    int getNum(){return num;}
    int getQuant(){return quantity;}

    string getSY()const{return st.getSY();}
    double getP()const{return st.getP();}
};

#endif // TICKET_HPP_INCLUDED
