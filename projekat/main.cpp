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
//#include "funkcije.hpp"


/*
    prvo ide registracija koja ce biti uradjena pomocu setera u funkciji meni kad korisnik to izabere
    kada se kupi neki stock, proverava se da li moze da se kupi, ako moze kupuje se i cena se oduzima
    od balance, postavlja se nova cena deonice za sve koji imaju akaunt, i kupljene deonice se upisuju u portfolio klasu
    svaki akaunt ima posebnu portfolio klasu, kao i history klasu.Svaki put kad s epromeni balance pravi se novi objekat history
    i svi history objekti se pisu u jedan history fajl, svaki korisnik ima poseban ovaj fajl
*/
Sector promeniEnumSec(int i)
{
    switch(i)
    {
    case 0: return Tech;
    case 1: return Finansije;
    case 2: return Medicina;
    case 3: return Hemija;
    case 4: return Rudarstvo;
    case 5: return Prehrana;
    case 6: return Nekretnine;
    case 7: return Transport;
    case 8: return Energetika;
    }
}
Valuta promeniUenumV(int i)
{
    switch(i)
    {
    case 0: return eur;
    case 1: return usd;
    case 2: return gbp;
    case 3: return jpy;
    case 4: return chf;
    case 5: return aud;
    }
}
string PromeniUString(double a)
{
    auto str= to_string(a);
    return str;
}
vector<string> splitSen(string str, char c=',')
{
    string w = "";
    vector<string> v;
    for (auto rem : str)
    {
        if (rem==c)
        {
            v.push_back(w);
            w="";
        }
        else
        {
            w=w+rem;
        }
    }
    v.push_back(w);

    return v;
}
Balance ucitajBalance(string i, int br)
{
    string linijab;
    vector<string> resultb;
    string naziv=i+PromeniUString(br)+"balance.txt";
    ifstream fajlb (naziv);
    if(fajlb.is_open())
        {
            while(getline(fajlb,linijab))
            {
                resultb = splitSen(linijab,'|');
                Balance b(promeniUenumV(stoi(resultb[0])),stod(resultb[1]),stoi(resultb[2]),stod(resultb[3]));
                return b;
            }
        }
        else
            cout<<"Neuspesno otvoren fajl"<<endl;
}
void ucitajAccounts(vector<Account> *accounts)
{
        string linija;
        vector<string> result;
        ifstream fajl ("accounts.txt");

        if (fajl.is_open())
        {
            while (getline(fajl,linija))
            {
                if (linija!="")
                {
                    result = splitSen(linija,'|');
                    Portfolio p;
                    Balance *b = new Balance(ucitajBalance(result[0],stoi(result[2])));
                    Account a(result[0],result[1],result[3],stoi(result[2]),b,&p);
                    accounts->push_back(a);
                }
            }
            fajl.close();
        }

        else
            cout << "Neuspesno otvoren fajl"<<endl;
}
void ucitajStocks(vector<Stock> *stocks)
{
        string linija;
        vector<string> result;
        ifstream fajl ("stocks.txt");
        if (fajl.is_open())
        {
            while (getline(fajl,linija))
            {
                if (linija!="")
                {
                    result = splitSen(linija,'|');

                    Stock s(result[0],stod(result[1]),stoi(result[2]),promeniEnumSec(stoi(result[3])),stod(result[4]));
                    stocks->push_back(s);
                }
            }
            fajl.close();
        }

        else
            cout << "Neuspesno otvoren fajl";
}
void ucitajBroker(vector<Broker> *br)
{
        string linija;
        vector<string> result;
        ifstream fajl ("broker.txt");
        if (fajl.is_open())
        {
            while (getline(fajl,linija))
            {
                if (linija!="")
                {
                    result = splitSen(linija,'|');

                    Broker b(result[0],result[1],stod(result[2]));
                    br->push_back(b);
                }
            }
            fajl.close();
        }

        else
            cout << "Neuspesno otvoren fajl";
}
void izbor_stock(vector<Stock> stonks)
{
    auto it=stonks.begin();
    while(it!=stonks.end())
    {
        IspisStock(*it);
        cout<<endl;
        it++;
    }
    return;
}

void pretrazi_vector_stock(vector<Stock> stonks)
{
    auto it=stonks.begin();
    while(it!=stonks.end())
    {
        cout<<"Naziv: "<<it->getSY()<<endl;
        it++;
    }
}
Stock* izaberi_stock(vector<Stock> *stonks)
{
    pretrazi_vector_stock(*stonks);
    string naziv;
    cout<<"Vas izbor deonice: ";
    cin>>naziv;
    int it=0;
    while(it<stonks->size())
    {
        if(naziv==stonks->at(it).getSY())
            return &stonks->at(it);
        it++;
    }
      cout<<"Ne postoji"<<endl;

}
void pretrazi_vector_broker(vector<Broker> br)
{
    for(auto it=br.begin();it!=br.end();it++)
    {
        cout<<"Naziv: "<<(*it).getName()<<endl;
    }

}
Broker* izaberi_broker(vector<Broker> *br)
{
    cout<<br<<endl;
    pretrazi_vector_broker(*br);
    string i;
    cout<<"Vas izbor brokera: ";
    cin>>i;
    for(int it=0;it<br->size();it++)
    {
        if(i==br->at(it).getName())
            return &br->at(it);
    }
     cout<<"Ne postoji"<<endl;
}
void isprazni_stock_fajl()
{
    ofstream fajl;
    fajl.open("stocks.txt", ofstream::out | ofstream::trunc);
    fajl.close();
    //isprazni se ceo fajl da bi se mogla upisati nova vrednost deonice na istom mestu kao pre
    //umesto da
}
void promeni_stock(vector<Stock> stonks, Stock st)
{
    for(auto it=stonks.begin();it!=stonks.end();it++)
    {
        if(st.getSY()==(*it).getSY())
            (*it)=st;
    }
    isprazni_stock_fajl();
    for(int i=0;i<stonks.size();i++)
    {
        stonks[i].pisiTxt('a');
    }
}
void kupi(Account *a,Portfolio *pom ,vector<Stock> *stonks)
{
    Stock *st=new Stock(izaberi_stock(stonks));
    cout<<"Kolicina: ";
    int q;
    cin>>q;
    Ticket t(rand()%2000001,q,st);
    vector<Broker> br;
    ucitajBroker(&br);
    cout<<&br<<endl;
    Broker *b=new Broker(izaberi_broker(&br));

    Buy_Sell bs(t,*b,a->getB());
    bool bol=bs.BuyStock(a->getIme(),a->getAcc());

    if(bol==true){
        cout<<st->getSY()<<endl;
        pom->setAnotherTicket(bs);
        cout<<"Dodato"<<endl;
        promeni_stock(*stonks, *st); // menja stari stock u bazi za novi (vrednosti)
        cout<<"Promenjeno u fajlu"<<endl;
        br.clear();
    }
    return;
}
int main()
{

    Balance bl(eur,10000,0,0);

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


    /*sm.pisiTxt('a');
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


   // Meni();

    return 0;
}
