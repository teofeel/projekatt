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

    double getAskPrice()const
    {
        return st->getP()+st->getSpread()+b.getSpread();
    }
    double getSellPrice()const
    {
        return st->getP()-st->getSpread();
    }

    bool BuyStock(string i, int acc)
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
            bl->pisiTxt(i,acc);
            return true;
        }
        else {
            cout<<"Nije moguce kupiti" <<endl;
            return false;
        }
    }

    void SellStock(string i, int acc)
    {
        double sell_price;
        for(int i=0;i<quantity;i++)
        {
            Ticket::Prodaj(st->getSpread());
            sell_price = st->getP()-st->getSpread()+b.getSpread();
        }
        bl->setBalance(bl->getBalance()+sell_price);
        bl->pisiTxt(i,acc);
    }
    void ispis()const
    {
        cout<<"odje 1"<<endl;
        cout<<"Symbol: "<<getStockSY()<<endl;
        cout<<"odje 1"<<endl;
        cout<<"Price: "<<getSellPrice()<<endl;
        cout<<"odje 1"<<endl;
        cout<<"Ticket: "<<num<<endl;
        cout<<"Quant: "<<quantity<<endl;
    }
    ~Buy_Sell()
    {
        brKup--;
    }
};

int Buy_Sell::brKup=0;
#endif // BUY_HPP_INCLUDED
