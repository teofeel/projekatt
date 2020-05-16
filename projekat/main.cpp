#include <iostream>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#include "account.hpp"
#include "boss.hpp"
#include "history.hpp"
#include "market.hpp"
#include "portfolio.hpp"
#include "funkcije.hpp"


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
    //Broker br("ICMarkets","IC_Live20",0.5);
    //Ticket t(5555,2,sm);
    Portfolio p;
    Account a("Pera","Peric","iiiiiiiii",50005,bl);
    History h(1,Februar,2019,bl);
    cout<<bl<<endl;
    cout<<a<<endl;
    cout<<h<<endl;
    Market m;
    cout<<m.getBrMarketa()<<endl;
    //Meni();
    //cout<<endl<<"© github.com/teofeel All rights reserved"<<endl;
    return 0;
}
