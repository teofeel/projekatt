#ifndef TICKET_HPP_INCLUDED
#define TICKET_HPP_INCLUDED
#include <cstdlib>
#include "stock.hpp"

//sve tickete upisujem u portfolio.txt
class Ticket{
protected:
    int num;
    int quantity;
    Stock st;
public:
    Ticket():st()
    {
        num=0;
        quantity=0;
    }
    Ticket(const Stock &s1):st(s1.getSY(),s1.getP(),s1.getNS(),s1.getS(),s1.getSpread())
    {
        num=0;
        quantity=0;
    }
    Ticket(int n, int quant,const Stock &st1): st(st1.getSY(),st1.getP(),st1.getNS(),st1.getS(),st1.getSpread())
    {
        num=n;
        quantity=quant;
    }
    Ticket(const Ticket &t1): st(t1.st)
    {
        num=t1.num;
        quantity=t1.quantity;
    }

    void setNum(){num=rand()%2000001;}
    void setQuant(int q){quantity=q;}

    int getNum()const{return num;}
    int getQuant()const{return quantity;}

    Stock getStock()const{return st;}
    string getStockSY()const{return st.getSY();}
    double getStockPrice()const{return st.getP();}
    double getStockSpread()const{return st.getSpread();}

    void IspisiTicketa()
    {
        cout<<"Broj ticketa: "<<num<<endl;
        cout<<"Naziv deonice: "<<st.getSY()<<endl;
        cout<<"Broj kupljenih/prodatih deonica: "<<quantity<<endl;

    }
};

#endif // TICKET_HPP_INCLUDED
