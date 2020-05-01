#include <iostream>
#include <fstream>

using namespace std;

#include "account.hpp"
#include "balance.hpp"
#include "boss.hpp"
#include "broker.hpp"
#include "buy.hpp"
#include "history.hpp"
#include "market.hpp"
#include "portfolio.hpp"
#include "stock.hpp"
#include "ticket.hpp"

/*
    prvo ide registracija koja ce biti uradjena pomocu setera u funkciji meni kad korisnik to izabere
    kada se kupi neki stock, proverava se da li moze da se kupi, ako moze kupuje se i cena se oduzima
    od balance, postavlja se nova cena deonice za sve koji imaju akaunt, i kupljene deonice se upisuju u portfolio klasu
    svaki akaunt ima posebnu portfolio klasu, kao i history klasu.Svaki put kad s epromeni balance pravi se novi objekat history
    i svi history objekti se pisu u jedan history fajl, svaki korisnik ima poseban ovaj fajl
*/

int main()
{
    Stock sm("APPL",280,50000,Tech,0.5);

    Balance bl(eur,10000,0,0);
    Broker br("ICMarkets","IC_Live20",0.5);
    Ticket t(5555,2,sm);
    cout<<"Pre kupovine: "<<sm.getP()<<endl;
    Buy_Sell bs(t,br,bl);
    bs.BuyStock();
    cout<<"AskPrice:"<<bs.getAskPrice()<<endl;
    sm.setP(bs.getStockPrice());
    cout<<"Krajnja cena: "<<sm.getP()<<endl;
    return 0;
}
