#ifndef BUY_HPP_INCLUDED
#define BUY_HPP_INCLUDED
#include "ticket.hpp"
#include "broker.hpp"
#include "stock.hpp"
//dodajemo spread iz stocka i brokera
class Buy: public Ticket{
public:
    //na stock.price i stock.spread iz ticketa dodajemo spread brokera
};

#endif // BUY_HPP_INCLUDED
