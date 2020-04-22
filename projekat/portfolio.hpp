#ifndef PORTFOLIO_HPP_INCLUDED
#define PORTFOLIO_HPP_INCLUDED
#include "history.hpp"
#include "buy.hpp"
#include "sell.hpp" //za novu cenu tj
class Portfolio:public History{
private:
    double curr_price;
public:
    //double getCurPrice(){return st.getNewP()-} metoda
};

#endif // PORTFOLIO_HPP_INCLUDED
