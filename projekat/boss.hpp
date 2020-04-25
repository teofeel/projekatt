#ifndef BOSS_HPP_INCLUDED
#define BOSS_HPP_INCLUDED
#include <string>
#include "stock.hpp"

enum Iskustvo{pocetnik, senior};
class Boss{
private:
    string ime;
    string prezime;
    Iskustvo i;
    Stock s;
public:
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
};

#endif // BOSS_HPP_INCLUDED
