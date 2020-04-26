#ifndef ACCOUNT_HPP_INCLUDED
#define ACCOUNT_HPP_INCLUDED
#include <string>
#include "balance.hpp"
#include "portfolio.hpp"
//radi
//akount baza podataka, iz nje pristupamo portfolio.txt, history.txt
//svaki akount ima poseban portfolio.txt, history.txt
class Account{
private:
    string ime;
    string prezime;
    int  acc_num;
    //string password;
    Balance b; //koliko para imamo na racunu isto iz fajla treba da se ispise
public:
    Account():b()
    {
        ime="Ime";
        prezime="prezime";
        acc_num=0;
    }
    Account(const Balance &b):b(b.getValuta(),b.getBalance(),b.getCredit(),b.getDeposit())
    {
        ime="Ime";
        prezime="Prezime";
        acc_num=0;
    }
    Account(string i,string p, int a,const Balance &b):b(b.getValuta(),b.getBalance(),b.getCredit(),b.getDeposit())
    {
        ime=i;
        prezime=p;
        acc_num=a;
    }
    Account (string i,string p, int a, Valuta vv, double ss, int c, double d): b(vv,ss,c,d)
    {
        ime=i;
        prezime=p;
        acc_num=a;
    }

    void setIme(string i){ime=i;}
    void setPrezime(string p){prezime=p;}
    void setAcc(int a){acc_num=a;}

    Balance getB()const{return b;}
    string getIme(){return ime;}
    string getPrezime(){return prezime;}
    int getAcc()const{return acc_num;}

    Valuta getV()const{return b.getValuta();}
    double getBalans()const{return b.getBalance();}
    int getC()const{return b.getCredit();}
    double getD()const{return b.getDeposit();}

    //login funkcija

};

#endif // ACCOUNT_HPP_INCLUDED
