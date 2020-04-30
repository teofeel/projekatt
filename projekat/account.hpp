#ifndef ACCOUNT_HPP_INCLUDED
#define ACCOUNT_HPP_INCLUDED
#include <string>

#include "portfolio.hpp"
#include "balance.hpp"
class Account{
private:
    string ime;
    string prezime;
    int  acc_num;
    string password;
    Balance b;
public:
    Account():b()
    {
        ime="Ime";
        prezime="prezime";
        password="password";
        acc_num=0;
    }
    Account(const Balance &b):b(b.getValuta(),b.getBalance(),b.getCredit(),b.getDeposit())
    {
        ime="Ime";
        prezime="Prezime";
        password="Password";
        acc_num=0;
    }
    Account(string i,string p,string pas, int a,const Balance &b):b(b.getValuta(),b.getBalance(),b.getCredit(),b.getDeposit())
    {
        ime=i;
        prezime=p;
        password=pas;
        acc_num=a;
    }
    Account (string i,string p,string pas, int a, Valuta vv, double ss, int c, double d): b(vv,ss,c,d)
    {
        ime=i;
        prezime=p;
        password=pas;
        acc_num=a;
    }

    void setIme(string i){ime=i;}
    void setPrezime(string p){prezime=p;}
    void serPassword(string p){password=p;}
    void setAcc(int a){acc_num=a;}

    Balance getB()const{return b;}
    string getIme(){return ime;}
    string getPrezime(){return prezime;}
    int getAcc()const{return acc_num;}

    Valuta getV()const{return b.getValuta();}
    double getBalans()const{return b.getBalance();}
    int getC()const{return b.getCredit();}
    double getD()const{return b.getDeposit();}

    bool Login(int accn, string pass)
    {
        if(accn==acc_num && pass==password)
            return true;
        else
            return false;
    }

};

#endif // ACCOUNT_HPP_INCLUDED
