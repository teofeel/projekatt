#ifndef SELL_HPP_INCLUDED
#define SELL_HPP_INCLUDED
#include "ticket.hpp"
#include "stock.hpp"
class Sell:public Ticket{
public:
    //ticket se zatvara i nova cena stocka se dodaje/oduzima od balance, a ticket se dodaje u hisotry
};

#endif // SELL_HPP_INCLUDED
