#ifndef BALANCE_HPP_INCLUDED
#define BALANCE_HPP_INCLUDED

enum Valuta{eur, usd, gbp, jpy, chf, aud};
string PromeniUString(int a)
{
    auto str= to_string(a);
    return str;
}
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
        izlaz<<"Valuta: "<<b.v<<endl;
        izlaz<<"Balans: "<<b.balance<<endl;
        izlaz<<"Kredit: "<<b.credit<<endl;
        izlaz<<"Deposit: "<<b.deposit<<endl;
        return izlaz;
    }
    void pisiTxt(string i,int br,char mode='w')
    {
        ofstream fajl;
        string naziv=i+PromeniUString(br)+"balance.txt";
        if (mode=='a'){
            fajl.open (naziv, ios_base::app);
        }
        else{
            fajl.open (naziv);
        }
        fajl<< v <<"|"<< balance <<"|"<< credit <<"|"<< deposit<<endl;
        fajl.close();
    }

    void citajAcc(string i,int br)
    {
        string linija;
        string naziv=i+PromeniUString(br)+"balance.txt";
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

#endif // BALANCE_HPP_INCLUDED
