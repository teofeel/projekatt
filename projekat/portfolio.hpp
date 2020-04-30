#ifndef PORTFOLIO_HPP_INCLUDED
#define PORTFOLIO_HPP_INCLUDED
#include <vector>
#include "balance.hpp"
#include "buy.hpp"
#include <ctime>

class Portfolio{
private:
    vector<Buy_Sell> bs;
    Balance bl;
public:
    Portfolio():bl(),bs(){}

    Portfolio(const Buy_Sell &t1, const Balance &b):bl(b.getValuta(),b.getBalance(),b.getCredit(),b.getDeposit())
    {
        bs.push_back(t1);
    }

    void setAnotherTicket(const Buy_Sell& t1)
    {
        bs.push_back(t1);
    }

    vector<Buy_Sell> getTicket()const{
        return bs;
    }

    double getCurr_Price()
    {
        double curr=0;
        for(int i=0; i<bs.size(); i++)
        {
            curr=curr+bs[i].getStockPrice()*bs[i].getQuant();
        }
        return curr;
    }

    Balance getBL()const{return bl;}
    Valuta getValuta()const{return bl.getValuta();}
    double getBalance()const{return bl.getBalance();}
    int getCredit()const{return bl.getCredit();}
    double getDeposit()const{return bl.getDeposit();}

};

#endif // PORTFOLIO_HPP_INCLUDED
