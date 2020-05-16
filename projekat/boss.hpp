#ifndef BOSS_HPP_INCLUDED
#define BOSS_HPP_INCLUDED
#include <string>
#include "stock.hpp"
#include "covek.hpp"
enum Iskustvo{pocetnik, senior};

class Boss:public Covek{
private:
    string ime;
    string prezime;
    Iskustvo i;
    Stock s;
public:
    Boss(): s("????",0,0,Tech,0)
    {
        ime="Ime";
        prezime="Prezime";
        i=pocetnik;
    }
    Boss(const Stock &s1): s(s1.getSY(),s1.getP(),s1.getNS(),s1.getS(),s1.getSpread())
    {
        ime="Ime";
        prezime="Prezime";
        i=pocetnik;
    }
    Boss(string i, string p, Iskustvo ii, const Stock &s1): s(s1)
    {
        ime=i;
        prezime=p;
        i=ii;
    }
    Boss(const Boss &b): s(b.s)
    {
        ime=b.ime;
        prezime=b.prezime;
        i=b.i;
    }
    void setIme(string i){ime=i;}
    void setPrezime(string p){prezime=p;}
    void setI(Iskustvo ii){i=ii;}

    string getIme(){return ime;}
    string getPrezime(){return prezime;}
    Iskustvo getI(){return i;}

    string getComp(){return s.getSY();}

    void ispisCoveka()
    {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
    }

    double vrednost()
    {
        return s.getMarketCap();
    }
};

#endif // BOSS_HPP_INCLUDED
