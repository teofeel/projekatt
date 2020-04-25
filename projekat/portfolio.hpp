#ifndef PORTFOLIO_HPP_INCLUDED
#define PORTFOLIO_HPP_INCLUDED
#include <vector>
#include "history.hpp"
#include "buy.hpp"
#include "sell.hpp"

//poseban fajl
//upisuju se ticketi u ovu bazu
//proverava se iz portfolio baze da li moze da se proda neka deonica
//kada prodajemo deonicu
class Portfolio{
private:
    vector<Ticket> t;
public:
    Portfolio(const Ticket &t1)
    {
        t.push_back(t1);
    }

    void setAnotherTicket(const Ticket& t1)
    {
        t.push_back(t1);
    }

    vector<Ticket> getTicket()const{

        return t;
    }

    double getCurr_Price()
    {
        double curr=0;
        for(int i=0; i<t.size(); i++)
        {
            curr=curr+t[i].getStockPrice()*t[i].getQuant();
        }
        return curr;
    }



};

#endif // PORTFOLIO_HPP_INCLUDED
