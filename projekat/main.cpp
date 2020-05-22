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

    /*Balance bl(eur,10000,0,0);

    vector<Stock> stonk;
    ucitajStocks(&stonk);

    vector<Account> a;
    ucitajAccounts(&a);

    //a[0].getPort()->ispisPortfolia();
    Broker br;
    Broker br2;
    Balance b;
    Balance b2;
    Ticket t;
    Buy_Sell bs(t,br,&b);
    Buy_Sell bs1(t,br2,&b2);
    //Portfolio *p=new Buy_Sell(&bs);
    //p.setAnotherTicket(&bs1);
    //p.ispisPortfolia();
    //bs.ispis();
    //cout<<bs.getStockPrice()<<endl;
    //cout<<bs.getStockSY()<<endl;

    kupi(&a[0],a[0].getPort(),&stonk);
    cout<<"Vratili se u main"<<endl;;
    ucitajStocks(&stonk);
    a[0].getPort()->ispisPortfolia();


    sm.pisiTxt('a');
    sm1.pisiTxt('a');
    sm2.pisiTxt('a');
    sm3.pisiTxt('a');
    Stock sm("APPL",280,50000000,Tech,0.5);
    Stock sm2("MRNA",66,250000,Medicina,0.3);
    Stock sm3("AERO",10,1000000,Nekretnine,0.2);
    //bl.pisiTxt('a');
    //
    //Ticket t(5555,2,sm);


    History h(1,Februar,2019,bl);
    cout<<bl<<endl;
    cout<<a<<endl;
    cout<<h<<endl;
    Market m;
    cout<<m.getBrMarketa()<<endl;
    Broker br1("ICMarkets","ICMarketsSC",0.05);
    Broker br2("Blueberry","BlueberrySC",0.03);
    Broker br3("IGBroker","IGSC",0.08);
    br1.pisiTxt('a');
    br2.pisiTxt('a');
    br3.pisiTxt('a');

    Broker br("ICMarkets","IC_Live20",0.5);

    Ticket t(12223,2,&sm1);
    Buy_Sell b(t,br,&bl);
    b.BuyStock("neko",1112);
    Portfolio p;
    p.setAnotherTicket(&b);
    cout<<p.getCurr_Price()<<endl;*/


    Meni();

    return 0;
}
