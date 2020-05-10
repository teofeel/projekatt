#ifndef MARKET_HPP_INCLUDED
#define MARKET_HPP_INCLUDED
#include "stock.hpp"

class Market{
private:
    string name;
    string loc;
    vector<Stock> st;
    static int brmarketa;
public:
    Market():st()
    {
        name="Naziv";
        loc="Lokacija";
        brmarketa++;
    }
    Market(string n, string l, const Stock &st1)
    {
        name=n;
        loc=l;
        st.push_back(st1);
        brmarketa++;
    }
    Market(string n, string l, vector<Stock> &st1)
    {
        name=n;
        loc=l;
        st=st1;;
        brmarketa++;
    }
    void setName(string s){name=s;}
    void setL(string l){loc=l;}
    void setAnotherST(const Stock& st1)
    {
        st.push_back(st1);
    }
    int getBrMarketa(){return brmarketa;}
    string getName(){return name;}
    string getLoc(){return loc;}

    double getValue()
    {
        double value=0;
        for(int i=0; i<st.size();i++)
        {
            value=value + st[i].getMarketCap();
        }
        return value;
    }
};

int Market::brmarketa=0;

#endif // MARKET_HPP_INCLUDED
