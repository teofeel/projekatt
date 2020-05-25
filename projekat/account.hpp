#ifndef ACCOUNT_HPP_INCLUDED
#define ACCOUNT_HPP_INCLUDED
#include <string>
#include "balance.hpp"
#include "portfolio.hpp"
#include "covek.hpp"
class Account: public Covek{
private:
    string ime;
    string prezime;
    int  acc_num;
    string password;
    Balance *b;
    Portfolio *p;
public:
    Account():b(),p()
    {
        ime="Ime";
        prezime="prezime";
        password="password";
        acc_num=0;
    }
    Account( Balance *bal,  Portfolio *pp)
    {
        ime="Ime";
        prezime="Prezime";
        password="Password";
        b=new Balance(bal);
        p=new Portfolio(pp);
        acc_num=0;
    }
    Account(string i,string p,string pas, int a, Balance* bal,  Portfolio *pp):b(bal), p(pp)
    {
        ime=i;
        prezime=p;
        password=pas;
        acc_num=a;
    }
   /* Account (string i,string p,string pas, int a, Valuta vv, double ss, int c, double d): b(vv,ss,c,d)
    {
        ime=i;
        prezime=p;
        password=pas;
        acc_num=a;
    }*/

    void setIme(string i){ime=i;}
    void setPrezime(string p){prezime=p;}
    void setPassword(string p){password=p;}
    void setAcc(int a){acc_num=a;}
    void setBalance(Balance* bal){b=bal;}

    Balance* getB(){return b;}
    Portfolio* getPort(){return p;}
    string getIme()const{return ime;}
    string getPas()const{return password;}
    string getPrezime()const{return prezime;}
    int getAcc()const{return acc_num;}

    Valuta getV()const{return b->getValuta();}
    double getBalans()const{return b->getBalance();}
    int getC()const{return b->getCredit();}
    double getD()const{return b->getDeposit();}

    bool Login(string im,int accn, string pass)
    {
        if(accn==acc_num && pass==password && im==ime)
            return true;
        else
            return false;
    }

    friend ostream& operator<<(ostream& izlaz,const Account& a)
    {
        izlaz<<"Ime i prezime:"<<endl;
        izlaz<<a.ime<<endl;
        izlaz<<a.prezime<<endl;
        izlaz<<a.acc_num<<endl;
        izlaz<<a.b<<endl;
        return izlaz;
    }

    void pisiTxt(char mode='w')
    {
        ofstream fajl;

        if (mode=='a'){
            fajl.open ("accounts.txt", ios_base::app);
        }
        else{
            fajl.open ("accounts.txt");
        }
        fajl<< ime <<"|"<< prezime <<"|"<< acc_num <<"|"<< password<<endl;
        fajl.close();
    }

    void citajAcc()
    {
        string linija;
        ifstream fajl ("accounts.txt");
        if (fajl.is_open())
        {
            while ( getline (fajl,linija) )
            {
                cout << linija << '\n';
            }
            fajl.close();
        }

        else
            cout << "Neuspesno otvoren fajl";
    }
    void ispisCoveka()
    {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Broj racuna: "<<acc_num<<endl;
    }
    double vrednost()
    {
        return b->getBalance();
    }
};

#endif // ACCOUNT_HPP_INCLUDED
