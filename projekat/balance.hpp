#ifndef BALANCE_HPP_INCLUDED
#define BALANCE_HPP_INCLUDED

enum Valuta{eur, usd, gbp, jpy, chf, aud};
//
class Balance{
private:
    Valuta v;
    double s; //balance
    int credit; //pozajmica
    double deposit;
    double withdrawal;
public:
    Balance(Valuta vv, double ss, int c, double d)
    {
        v=vv;
        s=ss;
        credit=c;
        deposit = d;
        withdrawal=0;
    }
    Balance (const Balance &b)
    {
        v=b.v;
        s=b.s;
        credit=b.credit;
        deposit=b.deposit;
        withdrawal=b.withdrawal;
    }

    void setV(Valuta vv){v=vv;}
    void setS(double ss){s=ss;}
    void setC(int c){credit=c;}
    void setD(double d){deposit=d;}
    void setWithdrawal(double w){withdrawal=w;}

    Valuta getValuta()const{return v;}
    double getS()const{return s;}
    int getCredit()const{return credit;}
    double getDeposit()const{return deposit;}
    double getWithdrwal()const{return withdrawal;}

};

#endif // BALANCE_HPP_INCLUDED
