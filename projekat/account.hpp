#ifndef ACCOUNT_HPP_INCLUDED
#define ACCOUNT_HPP_INCLUDED
#include <string>
#include "balance.hpp"
#include "broker.hpp"
//metode: get new balance
class Account{
private:
    string ime;
    string prezime;
    int  acc_num;
    Balance b; //koliko para imamo na racunu
    Broker br; //kojeg borkera koristimo
public:
    Account (string i,string p, int a, Valuta vv, double ss, int c, double d,string n, string sn, double sp): b(vv,ss,c,d), br(n,sn,sp)
    {
        ime=i;
        prezime=p;
        acc_num=a;
    }
    void setIme(string i){ime=i;}
    void setPrezime(string p){prezime=p;}
    void setAcc(int a){acc_num=a;}

    Balance getB(){return b;}
    string getIme(){return ime;}
    string getPrezime(){return prezime;}
    int getAcc(){return acc_num;}

    Valuta getV()const{return b.getValuta();}
    double getSs()const{return b.getS();}
    int getC()const{return b.getCredit();}
    double getD()const{return b.getDeposit();}

    string getName()const{return br.getName();}
    string getSN()const{return br.getSN();}
    double getSpread()const{return br.getSpread();}
};

#endif // ACCOUNT_HPP_INCLUDED
