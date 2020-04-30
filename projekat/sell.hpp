#ifndef SELL_HPP_INCLUDED
#define SELL_HPP_INCLUDED
#include "ticket.hpp"
#include "stock.hpp"
#include "balance.hpp"


class Sell:public Ticket{
private:
    Balance b;
public:
    Sell(const Ticket &t,const Balance &bl):Ticket(t.getNum(),t.getQuant(),t.getStock()),b(bl.getValuta(),bl.getBalance(),bl.getCredit(),bl.getDeposit()){}


    double getSellPrice()
    {
        return st.getP()-st.getSpread();
    }

    void SellStock()
    {
        double sell_price;
        for(int i=0;i<quantity;i++)
        {
            sell_price = st.getP()-st.getSpread();
        }
        double a;
        a=b.getBalance()+sell_price;
        b.setBalance(a);
    }
};

#endif // SELL_HPP_INCLUDED
