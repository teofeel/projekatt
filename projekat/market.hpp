#ifndef MARKET_HPP_INCLUDED
#define MARKET_HPP_INCLUDED
#include "stock.hpp"
#include <vector>

class Market{
private:
    string name;
    string loc;
    vector <Stock> st; //deonice se citaju iz fajla
public:
    Market(string n, string l, const Stock &st1)
    {
        name=n;
        loc=l;
        st.push_back(st1);
    }

    void setName(string s){name=s;}
    void setL(string l){loc=l;}
    void setAnotherST(const Stock& st1)
    {
        st.push_back(st1);
    }

    string getName(){return name;}
    string getLoc(){return loc;}

    double getValue()
    {
        double value=0;
        for(int i=1; i<st.size();i++)
        {
            value=value + st[i].getMarketCap();
        }
        return value;
    }
};

#endif // MARKET_HPP_INCLUDED
