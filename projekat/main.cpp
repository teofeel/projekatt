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

    return 0;
}
