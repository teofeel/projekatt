#ifndef HISTORY_HPP_INCLUDED
#define HISTORY_HPP_INCLUDED
#include "balance.hpp"

#include <vector>

enum Mesec{Januar, Februar, Mart, April, Maj, Jun, Jul, Avgust, Septembar, Oktobar, Novembar, Decembar};

class History{
protected:
    int dan;
    Mesec m;
    int godina;
    Balance b;
public:
    History(int d, Mesec mm, int g, const Balance &b1): b(b1)
    {
        dan=d;
        m=mm;
        godina=g;
    }
    History(const History &h): b(h.b)
    {
        dan=h.dan;
        m=h.m;
        godina=h.godina;
    }

    void setDan(int d){dan=d;}
    void setM(Mesec mm){m=mm;}
    void setGodina(int g){godina=g;}

    Balance getB(){return b;}
    int getDan(){return dan;}
    Mesec getM(){return m;}
    int getGodina(){return godina;}

    Valuta getV()const{return b.getValuta();}
    double getBal()const{return b.getBalance();}
    int getC()const{return b.getCredit();}
    double getD()const{return b.getDeposit();}

};

#endif // HISTORY_HPP_INCLUDED
