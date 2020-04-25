#ifndef ACCOUNT_HPP_INCLUDED
#define ACCOUNT_HPP_INCLUDED
#include <string>
#include "balance.hpp"
#include "portfolio.hpp"

//akount baza podataka, iz nje pristupamo portfolio.txt, history.txt
//svaki akount ima poseban portfolio.txt, history.txt
class Account{
private:
    string ime;
    string prezime;
    int  acc_num;
    //string password;
    Balance b; //koliko para imamo na racunu isto iz fajla treba da se ispise
    Portfolio p; //ispis portfolija iz fajla
public:
    Account (string i,string p, int a, Valuta vv, double ss, int c, double d,const Portfolio &pt): b(vv,ss,c,d), p(pt)
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

    double getInvestment(){return p.getCurr_Price();}

    //login funkcija

};

#endif // ACCOUNT_HPP_INCLUDED
