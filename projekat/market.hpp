#ifndef MARKET_HPP_INCLUDED
#define MARKET_HPP_INCLUDED
#include "stock.hpp"

class Market{
private:
    string name;
    string loc;
    vector<Stock*> st;
    static int brmarketa;
public:
    Market()
    {
        name="Naziv";
        loc="Lokacija";
        brmarketa++;
    }
    Market(string n, string l,Stock *st1)
    {
        name=n;
        loc=l;
        st.push_back(st1);
        brmarketa++;
    }
    Market(string n, string l, vector<Stock*> st1)
    {
        name=n;
        loc=l;
        st=st1;;
        brmarketa++;
    }
    void setName(string s){name=s;}
    void setL(string l){loc=l;}
    void setAnotherST(Stock *st1)
    {
        st.push_back(st1);
    }
    int getBrMarketa(){return brmarketa;}
    string getName(){return name;}
    string getLoc(){return loc;}

    double getValue()
    {
        double value=0;
        for(auto i=st.begin(); i!=st.end();i++)
        {
            value=value+(*i)->getMarketCap();
        }
        return value;
    }
    void ispis_kompanija()
    {
        for(auto i=st.begin(); i!=st.end();i++)
        {
            cout<<(*i)->getSY()<<endl;
        }
    }
    bool pronadji_kompanija(string si)
    {
        for(auto i=st.begin(); i!=st.end();i++)
        {
            if((*i)->getSY()==si)
            {
                return true;
            }
        }
        return false;
    }
    void izbaci(string si)
    {
        bool p;
        for(auto it=st.begin();it!=st.end();it++)
        {
            if((*it)->getSY()==si)
            {
                st.erase(it);
                p=true;
            }
        }
        if(!p) cout<<"Ne postoji"<<endl;
    }
    ~Market()
    {
        brmarketa--;
    }
};

int Market::brmarketa=0;

#endif // MARKET_HPP_INCLUDED
