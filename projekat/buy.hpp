#ifndef BUY_HPP_INCLUDED
#define BUY_HPP_INCLUDED
#include "ticket.hpp"
#include "broker.hpp"
#include "balance.hpp"

class Buy_Sell: public Ticket{
private:
    Broker b;
    Balance *bl;
    static int brKup;
public:
    Buy_Sell():Ticket(),b(),bl(){brKup++;}
    Buy_Sell(Ticket t,const Broker &br,Balance *bal):
        Ticket(t), b(br.getName(),br.getSN(),br.getSpread()), bl(bal){brKup++;}
    Buy_Sell(const Buy_Sell &bs):
        Ticket(bs),b(bs.b),bl(bs.bl){brKup++;}

    Broker getBroker()const{return b;}

    double getAskPrice()
    {
        return st->getP()+st->getSpread()+b.getSpread();
    }
    double getSellPrice()
    {
        return st->getP()-st->getSpread();
    }

    void BuyStock()
    {
        double buy_price;
        for(int i=0; i<quantity;i++)
        {
            buy_price=st->getP()+st->getSpread()+b.getSpread();
        }
        if(buy_price<=bl->getBalance()){
            for(int i=0; i<quantity;i++)
            {
                Ticket::Kupi(st->getSpread());
            }
        bl->setBalance(bl->getBalance()-buy_price);
        }
        else cout<<"Nije moguce kupiti" <<endl;
    }

    void SellStock()
    {
        double sell_price;
        for(int i=0;i<quantity;i++)
        {
            Ticket::Prodaj(st->getSpread());
            sell_price = st->getP()-st->getSpread()+b.getSpread();
        }
        bl->setBalance(bl->getBalance()+sell_price);
    }
    void ispis()
    {
        cout<<"Symbol: "<<getStockSY()<<endl;
        cout<<"Price: "<<getSellPrice()<<endl;
        cout<<"Ticket: "<<getNum()<<endl;
        cout<<"Quant: "<<getQuant()<<endl;
    }
    ~Buy_Sell()
    {
        brKup--;
    }
};

int Buy_Sell::brKup=0;
#endif // BUY_HPP_INCLUDED
