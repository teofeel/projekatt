#ifndef HISTORY_HPP_INCLUDED
#define HISTORY_HPP_INCLUDED
#include "balance.hpp"


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

    friend ostream& operator<<(ostream& izlaz,const History& h)
    {
        izlaz<<h.dan<<"."<<h.m+1<<"."<<h.godina<<"."<<endl;
        izlaz<<"Balans: "<<h.b<<endl;
        return izlaz;
    }

    void pisiTxt(string ime,string acc,char mode='w')
    {
        ofstream fajl;
        string naziv=ime+acc+"history.txt";
        if (mode=='a'){
            fajl.open (naziv, ios_base::app);
        }
        else{
            fajl.open (naziv);
        }
        fajl<< dan <<"|"<< m <<"|"<< godina <<endl;
        fajl.close();
    }

    void citajStocks(string ime, string acc)
    {
        string linija;
        string naziv=ime+acc+"history.txt";
        ifstream fajl (naziv);
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
};

#endif // HISTORY_HPP_INCLUDED
