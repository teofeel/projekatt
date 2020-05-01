#ifndef BUY_HPP_INCLUDED
#define BUY_HPP_INCLUDED
#include "ticket.hpp"
#include "broker.hpp"
#include "balance.hpp"
#include "stock.hpp"

class Buy_Sell: public Ticket{
private:
    Broker b;
    Balance bl;
public:
    Buy_Sell():Ticket(),b(),bl(){}
    Buy_Sell(const Ticket &t,const Broker &br,const Balance &bal):
        Ticket(t), b(br.getName(),br.getSN(),br.getSpread()), bl(bal.getValuta(),bal.getBalance(),bal.getCredit(),bal.getDeposit()){}
    Buy_Sell(const Buy_Sell &bs):
        Ticket(bs),b(bs.getBroker()),bl(bs.getBalans()){}

    Broker getBroker()const{return b;}
    Balance getBalans()const{return bl;}

    double getAskPrice()
    {
        return st.getP()+st.getSpread()+b.getSpread();
    }
    double getSellPrice()
    {
        return st.getP()-st.getSpread();
    }

    void BuyStock()
    {
        double buy_price;
        for(int i=0; i<quantity;i++)
        {
            Ticket::Kupi(st.getSpread());
            //st.setP(st.getP()+st.getSpread());
            buy_price=st.getP()+st.getSpread()+b.getSpread();
        }
        bl.setBalance(bl.getBalance()-buy_price);
        //cout<<"Nakon kupovine: "<<st.getP()<<endl;
    }

    void SellStock()
    {
        double sell_price;
        for(int i=0;i<quantity;i++)
        {
            Ticket::Prodaj(st.getSpread());
            sell_price = st.getP()-st.getSpread();
        }
        bl.setBalance( bl.getBalance()+sell_price);
    }


};


#endif // BUY_HPP_INCLUDED
