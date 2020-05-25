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
    Portfolio( vector<Buy_Sell*> &bs1)
    {
        bs=bs1;
    }
    Portfolio(const Portfolio &p)
    {
        bs=p.getTicket();
    }
    Portfolio(Portfolio *p)
    {
        bs=p->bs;
    }
    void setAnotherTicket(Buy_Sell *b)
    {
        bs.push_back(b);
    }

    vector<Buy_Sell*> getTicket()const{
        return bs;
    }


    double getCurr_Price()const
    {
        double curr=0;
        for(auto i=bs.begin(); i!=bs.end(); i++)
        {
            curr=curr+(*i)->getQuant()*(*i)->getStockPrice();
        }
        return curr;
    }
    Stock* getST(int n)
    {
        bool p;
        for(auto it=bs.begin();it!=bs.end();it++)
        {
            if(n=(*it)->getNum())
            {
                Stock *sm=(*it)->getStock();
                p=true;
                return sm;
            }
        }
        if(!p) cout<<"Ne postoji"<<endl;
    }
    bool pretraziBS(int n)
    {
        bool p;
        for(auto it=bs.begin();it!=bs.end();it++)
        {
            if(n==(*it)->getNum())
            {
                p=true;
                return p;
            }
        }
        if(!p) cout<<"Ne postoji"<<endl;
        return 0;
    }

    bool izbaci(int n,string ime, int acc)
    {
        bool p;
        for(auto it=bs.begin();it!=bs.end();it++)
        {
            if(n==(*it)->getNum())
            {
                (*it)->SellStock(ime,acc);
                bs.erase(it);
                p=true;
                return p;
            }
        }
        if(!p) cout<<"Ne postoji"<<endl;
    }

    void ispisPortfolia()
    {
        for(int it=0;it!=bs.size();it++)
        {
            bs[it]->ispis();
        }
    }
    void ocisti(string ime, int acc)
    {
        for(auto it=bs.begin();it!=bs.end();it++)
        {
                (*it)->SellStock(ime,acc);
        }
    }
};

#endif // PORTFOLIO_HPP_INCLUDED
