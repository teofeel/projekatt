#ifndef BALANCE_HPP_INCLUDED
#define BALANCE_HPP_INCLUDED

enum Valuta{eur, usd, gbp, jpy, chf, aud};

class Balance{
private:
    Valuta v;
    double balance;
    int credit;
    double deposit;
public:
    Balance()
    {
        v=eur;
        balance=0;
        credit=0;
        deposit=0;
    }
    Balance(Valuta vv, double ss, int c, double d)
    {

        v=vv;
        balance=ss;
        credit=c;
        deposit = d;
    }
    Balance (const Balance &b)
    {
        v=b.v;
        balance=b.balance;
        credit=b.credit;
        deposit=b.deposit;
    }

    void setV(Valuta vv){v=vv;}
    void setBalance(double ss){balance=ss;}
    void setC(int c){credit=c;}
    void setD(double d){deposit=d;}

    Valuta getValuta()const{return v;}
    double getBalance()const{return balance;}
    int getCredit()const{return credit;}
    double getDeposit()const{return deposit;}

    void newBalance()
    {
        balance=balance+deposit;
        deposit=0;
    }
    friend ostream& operator<<(ostream& izlaz,const Balance& b)
    {
        izlaz<<b.v<<endl;
        izlaz<<b.balance<<endl;
        izlaz<<b.credit<<endl;
        izlaz<<b.deposit<<endl;
        return izlaz;
    }
    void pisiTxt(char mode='w')
    {
        ofstream fajl;

        if (mode=='a'){
            fajl.open ("balance.txt", ios_base::app);
        }
        else{
            fajl.open ("balance.txt");
        }
        fajl<< v <<"|"<< balance <<"|"<< credit <<"|"<< deposit<<endl;
        fajl.close();
    }

    void citajAcc()
    {
        string linija;
        ifstream fajl ("balance.txt");
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

#endif // BALANCE_HPP_INCLUDED
