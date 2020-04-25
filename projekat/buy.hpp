#ifndef BUY_HPP_INCLUDED
#define BUY_HPP_INCLUDED
#include "ticket.hpp"
#include "broker.hpp"
#include "stock.hpp"
//oduzimamo ask_price*quant od balance i upisujemo u history fajl
class Buy: public Ticket{
private:
    double ask_price;
public:
    Buy(const Ticket &t):Ticket(t.getNum(),t.getQuant(),t.getStock()),ask_price((t.getStockPrice()+t.getStockSpread())*t.getQuant()){}
    void setAskPrice(const Stock &s, const Broker &b)
    {
        ask_price = s.getP()+s.getSpread()+b.getSpread();
    }

    double getAskPrice(){return ask_price;}

    void BuyStock()
    {
        for(int i=0; i<quantity;i++)
        {
            st.setP(st.getP()+st.getSpread());
        }
    }

    void IspisiTicket()
    {
        Ticket::IspisiTicketa();
        cout<<"Tipa: Buy"<<endl;
    }
};


#endif // BUY_HPP_INCLUDED
