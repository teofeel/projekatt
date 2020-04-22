#ifndef STOCK_HPP_INCLUDED
#define STOCK_HPP_INCLUDED
#include "market.hpp"
enum Sector{Tech, Finansije, Medicina, Hemija, Rudarstvo, Prehrana, Nekretnine, Prevoz, Energetika};

class Stock{
private:
    string symbol;
    double market_cap;
    double price;
    int num_shares;
    Sector s;
    double spread; // dodaje se na price kad se kupuje
public:
    Stock(string s, double mc, double p, int ns, Sector ss, double sp)
    {
        symbol=s;
        market_cap=mc;
        price=p;
        num_shares=ns;
        s=ss;
        spread=sp;
    }
    Stock(const Stock &st1)
    {
        symbol=st1.symbol;
        market_cap=st1.market_cap;
        price=st1.price;
        num_shares=st1.num_shares;
        s=st1.s;
        spread=st1.spread;
    }

    void setSY(string s){symbol=s;}
    void setMC(double mc){market_cap=mc;}
    void setP(double p){price=p;}
    void setNS(int ns){num_shares=ns;}
    void setS(Sector ss){s=ss;}
    void setSpread(double sp){spread=sp;}

    string getSY()const{return symbol;}
    double getMC()const{return market_cap;}
    double getP()const{return price;}
    int getNS()const{return num_shares;}
    Sector getS()const{return s;}
    double getSpread()const{return spread;}
};

#endif // STOCK_HPP_INCLUDED
