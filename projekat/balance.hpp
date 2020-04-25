#ifndef BALANCE_HPP_INCLUDED
#define BALANCE_HPP_INCLUDED

enum Valuta{eur, usd, gbp, jpy, chf, aud};

class Balance{
private:
    Valuta v;
    double balance; //balance
    int credit; //pozajmica
    double deposit;
public:
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

};

#endif // BALANCE_HPP_INCLUDED
