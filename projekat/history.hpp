#ifndef HISTORY_HPP_INCLUDED
#define HISTORY_HPP_INCLUDED
#include "balance.hpp"
#include "stock.hpp"
#include "ticket.hpp"
enum Mesec{Januar, Februar, Mart, April, Maj, Jun, Jul, Avgust, Septembar, Oktobar, Novembar, Decembar};
class History{
private:
    int dan;
    Mesec m;
    int godina;
    Balance b;
    double w; //withdrawal i oduzima se od balance.s
    //type,symbol: buy/sell
    Stock st;
    Ticket t;
public:
    History(int d, Mesec mm, int g, double ww, const Balance &b1, const Stock &st1, const Ticket &t1): b(b1), st(st1), t(t1)
    {
        dan=d;
        m=mm;
        godina=g;
        w=ww;
    }

    void setDan(int d){dan=d;}
    void setM(Mesec mm){m=mm;}
    void setGodina(int g){godina=g;}
    void setW(double ww){w=ww;}

    Balance getB(){return b;}
    int getDan(){return dan;}
    Mesec getM(){return m;}
    int getGodina(){return godina;}
    double getW(){return w;}

    Valuta getV()const{return b.getValuta();}
    double getS()const{return b.getS();}
    int getC()const{return b.getCredit();}
    double getD()const{return b.getDeposit();}

    string getSY()const{return st.getSY();}
    //double getMC()const{return st.getMC();}
    double getP()const{return st.getP();}
    //int getNS()const{return st.getNS();}
    Sector getSec()const{return st.getS();}
    double getSpread()const{return st.getSpread();}

    int getNum(){return t.getNum();}
    int getQuantity(){return t.getQuant();}
};

#endif // HISTORY_HPP_INCLUDED
