#ifndef PORTFOLIO_HPP_INCLUDED
#define PORTFOLIO_HPP_INCLUDED
#include <vector>
#include "balance.hpp"
#include "buy.hpp"
#include <ctime>

class Portfolio{
private:
    vector<Buy_Sell*> bs;
public:
    Portfolio():bs(){}

    Portfolio(Buy_Sell *t1)
    {
        bs.push_back(t1);
    }
    Portfolio(const vector<Buy_Sell*> &bs1)
    {
        bs=bs1;
    }
    Portfolio(const Portfolio &p)
    {
        bs=p.getTicket();
    }

    void setAnotherTicket(Buy_Sell *t1)
    {
        bs.push_back(t1);
    }

    vector<Buy_Sell*> getTicket()const{
        return bs;
    }

    int koliko()
    {
        return bs.size();
    }

    double getCurr_Price()
    {
        double curr=0;
        for(auto i=bs.begin(); i!=bs.end(); i++)
        {
            curr=curr+(*i)->getStockPrice()*(*i)->getQuant();
        }
        return curr;
    }

    void pretraziStock(string st)
    {
        bool p;
        for(auto it=bs.begin();it!=bs.end();it++)
        {
            if(st==(*it)->getStockSY())
            {
                (*it)->ispis();
                p=true;
            }
        }
        if(!p) cout<<"Ne postoji"<<endl;
    }

    void izbaci(int n)
    {
        bool p;
        for(auto it=bs.begin();it!=bs.end();it++)
        {
            if((*it)->getNum()==n)
            {
                bs.erase(it);
                p=true;
            }
        }
        if(!p) cout<<"Ne postoji"<<endl;
    }

    void ispisPortfolia()
    {
        for(auto it=bs.begin();it!=bs.end();it++)
        {
            (*it)->ispis();
            cout<<"         ///////"<<endl;
        }
    }
    void ocisti()
    {
        for(auto it=bs.begin();it!=bs.end();it++)
        {
                bs.erase(it);
        }
    }
};

#endif // PORTFOLIO_HPP_INCLUDED
