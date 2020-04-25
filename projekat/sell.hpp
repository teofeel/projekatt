#ifndef SELL_HPP_INCLUDED
#define SELL_HPP_INCLUDED
#include "ticket.hpp"
#include "stock.hpp"

//u portfolio.txt upisujemo sell_price
//dodajemo sell_price*quant ma balance i upisujemo u history fajl

class Sell:public Ticket{
private:
    double sell_price;
public:
    Sell(const Ticket &t):Ticket(t.getNum(),t.getQuant(),t.getStock()),sell_price(t.getStockPrice()*t.getQuant()){}

    void setSellPrice()
    {
        sell_price=st.getP()-st.getSpread();
    }

    double getSellPrice(){return sell_price;}

    void SellStock()
    {
        for(int i=0;i<quantity;i++)
        {
            sell_price = st.getP()-st.getSpread();
        }
    }
};

#endif // SELL_HPP_INCLUDED
