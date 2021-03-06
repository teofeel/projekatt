#ifndef TICKET_HPP_INCLUDED
#define TICKET_HPP_INCLUDED
#include "stock.hpp"



class Ticket{
protected:
    int num;
    int quantity;
    Stock *st;
public:
    Ticket()
    {
        num=0;
        st=new Stock();
        quantity=0;
    }
    Ticket(int n, int quant,Stock *s1)
    {
        num=n;
        st=s1;
        quantity=quant;
    }
    Ticket(const Ticket &t1)
    {
        num=t1.num;
        st=new Stock(t1.st);
        quantity=t1.quantity;
    }
    Ticket(Ticket* t)
    {
        num=t->num;
        st=new Stock(t->st);
        quantity=t->quantity;
    }
    void setNum(){num=rand()%2000001;}
    void setQuant(int q){quantity=q;}

    int getNum()const{return num;}
    int getQuant()const{return quantity;}

    Stock* getStock()const{return st;}
    string getStockSY()const{return st->getSY();}
    double getStockPrice()const{return st->getP();}
    double getStockSpread()const{return st->getSpread();}

    void Kupi(double spr)
    {
        st->Kupi(spr,1);
    }
    void Prodaj(double spr)
    {
        st->Prodaj(spr,1);
    }
    /*void IspisiTicketa()
    {
        cout<<"Broj ticketa: "<<num<<endl;
    }
    void ispisSt()
    {
        cout<<"Simbol: "<<st->getSY()<<endl;
        cout<<"Cena: "<<st->getP()<<endl;
        cout<<"Kolicina: "<<quantity<<endl;
    }*/
};

#endif // TICKET_HPP_INCLUDED
