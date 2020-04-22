#ifndef MARKET_HPP_INCLUDED
#define MARKET_HPP_INCLUDED
#include "stock.hpp"
#include <vector>
class Market{
private:
    string name;
    string loc;
    double value;
    vector <Stock> st;
public:
    Market(string n, string l, const Stock &st1)
    {
        name=n;
        loc=l;
        st.push_back(st1);
        value=st1.getP();
    }

    void setName(string s){name=s;}
    void setL(string l){loc=l;}
    void setAnotherST(const Stock& st1)
    {
        st.push_back(st1);
    }

    string getName(){return name;}
    string getLoc(){return loc;}
    void getValue()
    {
        for(int i=0; i<st.size();i++)
        {
            value=value + st[i].getP();
        }
    }
};

#endif // MARKET_HPP_INCLUDED
