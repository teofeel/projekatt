#ifndef STOCK_HPP_INCLUDED
#define STOCK_HPP_INCLUDED
#include "market.hpp"
enum Sector{Tech, Finansije, Medicina, Hemija, Rudarstvo, Prehrana, Nekretnine, Prevoz, Energetika};
//poseban fajl
class Stock{
protected:
    string symbol;
    double price;
    int num_shares;
    Sector s;
    double spread; // dodaje se na price kad se kupuje
public:
    Stock(string s, double p, int ns, Sector ss, double sp)
    {
        symbol=s;
        price=p;
        num_shares=ns;
        s=ss;
        spread=sp;
    }
    Stock(const Stock &st1)
    {
        symbol=st1.symbol;
        price=st1.price;
        num_shares=st1.num_shares;
        s=st1.s;
        spread=st1.spread;
    }

    void setSY(string s){symbol=s;}
    void setP(double p){price=p;}
    void setNS(int ns){num_shares=ns;}
    void setS(Sector ss){s=ss;}
    void setSpread(double sp){spread=sp;}

    string getSY()const{return symbol;}
    double getP()const{return price;}
    int getNS()const{return num_shares;}
    Sector getS()const{return s;}
    double getSpread()const{return spread;}

    double getMarketCap()const{return num_shares*price;}//izracunava trzisnu kapitalizciju

    friend void IspisStock(){}
};

void IspisStock(const Stock &st)
    {
        cout<<"Naziv deonice: "<<st.getSY()<<endl;
        cout<<"Cena: "<<st.getP()<<endl;
        cout<<"Broj izdatih deonica: "<<st.getNS()<<endl;
        cout<<"Trzisna Kapitalizacija: "<<st.getMarketCap()<<endl;
        cout<<"Sektor delatnosti: "<<st.getS()<<endl;
    }
#endif // STOCK_HPP_INCLUDED
