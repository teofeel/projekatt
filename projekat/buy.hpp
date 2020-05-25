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
    Buy_Sell(const Ticket& t,const Broker &br,Balance *bal):
        Ticket(t.getNum(),t.getQuant(),t.getStock()), b(br.getName(),br.getSN(),br.getSpread()), bl(bal){brKup++;}
        Buy_Sell(Ticket* t ,const Broker &br,Balance *bal):
        Ticket(t), b(br.getName(),br.getSN(),br.getSpread()), bl(bal){brKup++;}
    Buy_Sell(const Buy_Sell &bs):
        Ticket(bs),b(bs.getBroker()),bl(bs.getBalance()){brKup++;}
    Buy_Sell(int n,int quant,Stock *s ,const Broker &br,Balance *bal):
        Ticket(n,quant,s), b(br.getName(),br.getSN(),br.getSpread()), bl(bal){brKup++;}
    Buy_Sell(Buy_Sell *bs)
    {
        num=bs->num;
        quantity=bs->quantity;
        st=new Stock(bs->st);
        b=bs->b;
        bl=new Balance(bs->bl);
        brKup++;
    }
    Broker getBroker()const{return b;}
    Balance* getBalance()const{return bl;}
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
    void ispis()
    {
        cout<<"Ticket: "<<num<<endl;
        cout<<"Symbol: "<<Ticket::getStockSY()<<endl;
        cout<<"Price: "<<Ticket::getStockPrice()<<endl;
        cout<<"Quant: "<<quantity<<endl;
    }
    ~Buy_Sell()
    {
        brKup--;
    }
};

int Buy_Sell::brKup=0;
#endif // BUY_HPP_INCLUDED
