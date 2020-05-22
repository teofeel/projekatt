#ifndef FUNKCIJE_HPP_INCLUDED
#define FUNKCIJE_HPP_INCLUDED
#include <ctime>
string PromeniUString(double a)
{
    auto str= to_string(a);
    return str;
}
void Kraj_Prograna(vector<Account>* a)
{
    for(auto it=a->begin();it!=a->end();it++)
    {
        Portfolio *po=(*it).getPort();
        po->ocisti();
    }
}
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

Mesec promeniEnumMesec(int i)
{
    switch(i)
    {
    case 0: return Januar;
    case 1: return Februar;
    case 2: return Mart;
    case 3: return April;
    case 4: return Maj;
    case 5: return Jun;
    case 6: return Jul;
    case 7: return Avgust;
    case 8: return Septembar;
    case 9: return Oktobar;
    case 10: return Novembar;
    case 11: return Decembar;
    }

}
void dodaj_stock()
{
    cout<<"Koja je budala nasela na prevarau?"<<endl;
    string simp;
    cout<<"Symbol: ";
    cin>>simp;
    double c;
    cout<<"Cena: ";
    cin>>c;
    int ns;
    cout<<"Num_shares: ";
    cin>>ns;
    int sc;
    cout<<"Sektor: ";
    cin>>sc;
    double sp;
    cout<<"Spread: ";
    cin>>sp;
    Stock st(simp,c,ns,promeniEnumSec(sc),sp);
    cout<<"Jesi siguran da oces da namucis coveka?"<<endl;
    cout<<"Y/N"<<endl;
    char y;
    do{
        cin>>y;
        if(y=='Y')
            st.pisiTxt('a');
        else if(y=='N')
            return;
        else
            cout<<"Razmisli opet"<<endl;
    }while(y!='Y' || y!='N');
}
/*void napravi_market(vector<Stock>* stonks)
{
    string simp;
    cin>>simp;
    Market *m;

    for(auto it=stonks->begin();it!=stonks->end();it++)
    {
        if((*it)->getSY()==simp)
        {
            m->setAnotherST(it);
        }
    }
}*/
void Admin_mode(vector<Stock>* stonks)
{
    cout<<"Pa nije!"<<" ";
    cout<<"Pomaze Bog"<<endl;
    int ulaz;
    do{
        cin>>ulaz;
        switch(ulaz)
        {
        case 1:
            cout<<"More"<<endl;
            dodaj_stock();
            break;
        case 2:
            //napravi_market(stonks);
        case 44810:
            cout<<"**** **** ******** * **********"<<endl;
            break;
        case 0:
            return;
        default:
            cout<<"Idiote ti si pisao ovo, aj opet"<<endl;
            break;
        }
    }while(ulaz!=0);
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
                    Balance b =ucitajBalance(result[0],stoi(result[2]));
                    Account a(result[0],result[1],result[3],stoi(result[2]),&b,&p);
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
void ucitajHistory(string ime,int acc,vector<History> *h)
{
        string linija;
        vector<string> result;
        string naziv=ime+PromeniUString(acc)+"history.txt";
        ifstream fajl (naziv);
        if (fajl.is_open())
        {
            while (getline(fajl,linija))
            {
                if (linija!="")
                {
                    result = splitSen(linija);

                    History hi(stoi(result[0]),promeniEnumMesec(stoi(result[1])),stoi(result[2]),ucitajBalance(ime,acc));
                    h->push_back(hi);
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
Broker izaberi_broker(vector<Broker> br)
{
    cout<<"izaberi ";
    pretrazi_vector_broker(br);
    string i;
    cout<<"Vas izbor brokera: ";
    cin>>i;
    for(int it=0;it<br.size();it++)
    {
        if(i==br[it].getName())
            return br[it];
    }
     cout<<"Ne postoji"<<endl;
}
void isprazni_stock_fajl()
{
    ofstream fajl;
    fajl.open("stocks.txt", ofstream::out | ofstream::trunc);
    fajl.close();
    //isprazni se ceo fajl da bi se mogla upisati nova vrednost deonice na istom mestu kao pre
}
void promeni_stock(vector<Stock> stonks, Stock st)
{
    for(int i=0;i<stonks.size();i++)
    {
        if(st.getSY()==stonks[i].getSY())
        {
            stonks[i]=st;
        }
    }

   /* for(auto it=stonks->begin();it!=stonks->end();it++)
    {
        if(st.getSY()==(*it).getSY())
            (*it)=st;
    }*/
    isprazni_stock_fajl();
    for(int i=0;i<stonks.size();i++)
    {
        stonks[i].pisiTxt('a');
    }

}
void kupi(Account *a,Portfolio *pom ,vector<Stock> *stonks)
{
    Stock *st=izaberi_stock(stonks);
    cout<<"Kolicina: ";
    int q;
    cin>>q;
    Ticket t(rand()%2000001,q,st);
    vector<Broker> br;
    ucitajBroker(&br);
    Broker b(izaberi_broker(br));
    /*ako ne bi bilo pokazivaca na b dolazilo bi do memory violation sto bi crashovalo fajl
     */
    Buy_Sell *bs=new Buy_Sell(t,b,a->getB());
    bool bol=bs->BuyStock(a->getIme(),a->getAcc());
    if(bol==true){
        pom->setAnotherTicket(bs);

        promeni_stock(*stonks, *st); // menja stari stock u bazi za novi (vrednosti)
        br.clear();
    }
    else return;
}

void prodaj(Account *a, vector<Stock> *stonks)
{
    vector<Broker> br;
    ucitajBroker(&br);
    Broker b(izaberi_broker(br));

    Portfolio *p=a->getPort();
    p->ispisPortfolia();
    if(p!=NULL)
    {
        int n;
        cout<<"Broj tiketa: ";
        aaa:cin>>n;
        Stock *st;
        if(p->pretraziBS(n)==true)
        {
            st=p->getST(n);
            p->izbaci(n,a->getIme(),a->getAcc());

        }
        else
            goto aaa;

        promeni_stock(*stonks, *st); // menja stari stock u bazi za novi (vrednosti)
    }
    else
        cout<<"Prazno"<<endl;
    return;
}

void isprazni_balance_fajl(string ime, int acc)
{
    string naziv=ime+PromeniUString(acc)+"balance.txt";
    ofstream fajl;
    fajl.open(naziv, ofstream::out | ofstream::trunc);
    fajl.close();
}
void Deposit_balance(Account *a, Balance *b)
{
    double x;
    cout<<"Koliko zelite da dodate: ";
    cin >> x;
    if(x>10000)
    {
        x=10000;
        cout<<"Maksimum je 10000"<<endl;
        cout<<"10000 ce biti dodato na racun"<<endl;
    }
    b->setD(x);
    b->setBalance(b->getBalance()+b->getDeposit());
    isprazni_balance_fajl(a->getIme(),a->getAcc());
    b->pisiTxt(a->getIme(),a->getAcc(),'a');
}
void Podizanje_balance(Account a,Balance *b)
{
    double x;
    cout<<"Koliko zelite da podignete: ";
    cin >> x;
    if(x>10000)
    {
        x=10000;
        cout<<"Maksimum je 10000"<<endl;
        cout<<"10000 ce biti podignuto sa racuna"<<endl;
    }
    b->setBalance(b->getBalance()-x);
    isprazni_balance_fajl(a.getIme(),a.getAcc());
    b->pisiTxt(a.getIme(),a.getAcc(),'a');
}

void datum(Account a,Balance b, vector<History> *h)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    History h1( ltm->tm_mday,promeniEnumMesec(1+ltm->tm_mon),1900+ltm->tm_year,b);
    h1.pisiTxt(a.getIme(),PromeniUString(a.getAcc()),'a');
    h->push_back(h1);
}
void istorija(vector<History> h)
{
    cout<<endl;
    for(int i=0; i<h.size();i++)
    {
        cout<<h[i]<<endl;
        cout<<endl;
    }
}


void Meni_Balans(Account *a,Balance *b, vector<History> *h)
{
    int ulaz;
    //ucitajHistory(a.getIme(),a.getAcc(),h);
    do{
        cout<<"*************************************"<<endl;
        cout<<"1. Stanje"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. Podizanje"<<endl;
        cout<<"0. Nazad"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"> ";
        cin>>ulaz;
        switch(ulaz)
        {
            case 1:

                cout<<*b<<endl;
                break;
            case 2:
            {
                Deposit_balance(a,b);
                datum(*a,*b,h);
                break;
            }
            case 3:
            {
                Podizanje_balance(*a,b);
                datum(*a,*b,h);
                break;
            }
            default:
                cout<<"Opcija ne postoji. Unesite ponovo"<<endl;
                break;
        }

    }while(ulaz!=0);
}

void Meni_Portfolio(Portfolio *po)
{
    int ulaz;
    do{
        cout<<"*************************************"<<endl;
        cout<<"1. Moj portfolio"<<endl;
        cout<<"2. Kapital "<<endl;
        cout<<"0. Nazad"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"> ";
        cin>>ulaz;
        switch(ulaz)
        {
            case 1:
                po->ispisPortfolia();
                break;
            case 2:
                cout<<"Kapital: "<<po->getCurr_Price()<<endl;
                break;
            case 0:
                break;
            default:
                cout<<"Opcija ne postoji. Unesite ponovo"<<endl;
                break;
        }

    }while(ulaz!=0);
}
void Meni_Login(Account *a, vector<Stock> *stonks)
{
    int ulaz;
    vector<History> h;
    Balance b((ucitajBalance(a->getIme(),a->getAcc())));
    a->setBalance(&b);
    do{
        cout<<"*************************************"<<endl;
        cout<<"1. Portfolio (work in progress)"<<endl;
        cout<<"2. Balans"<<endl;
        cout<<"3. Deonice"<<endl;
        cout<<"4. Kupi"<<endl;
        cout<<"5. Prodaj"<<endl;
        cout<<"6. Istorija"<<endl;
        cout<<"0. Nazad"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"> ";

        cin>>ulaz;
        switch(ulaz)
        {
            case 1:
                Meni_Portfolio(a->getPort());
                break;
            case 2:
                Meni_Balans(a,a->getB(), &h);
                break;
            case 3:
                izbor_stock(*stonks);
                break;
            case 4:
                kupi(a,a->getPort(),stonks);
                stonks->clear();
                ucitajStocks(stonks); //zbog segmenntation faulta zbog overloada u promeni_stock mora svaki put da se isprazni vektor da bi se dobili novi podaci
                break;
            case 5:
                //prodaj(a,stonks);
                break;
            case 6:
                istorija(h);
                break;
            case 0:
                break;
            default:
                cout<<"Opcija ne postoji. Unesite ponovo"<<endl;
                break;
        }
    }while(ulaz!=0);
}

void Registracija(vector<Account> *accounts)
{

    cout<<"Ime: "<<endl;
    string i;
    cin>>i;
    cout<<"Prezime: "<<endl;
    string p;
    cin>>p;
    cout<<"Sifra: "<<endl;
    string pas;
    cin>>pas;
    cout<<"Ponovite sifru: "<<endl;
    string pas1;
    cin>>pas1;
    while(pas1!=pas){
            cout<<"Sifre se ne poklapaju: ";
            cin>>pas1;
    }
    int acc=rand()%10000000;
    cout<<"Broj racuna: "<<acc<<endl;
    Balance b;
    Portfolio po;
    Account a(i,p,pas,acc,&b,&po);
    a.pisiTxt('a');
    b.pisiTxt(a.getIme(),a.getAcc(),'a');
    accounts->push_back(a);
    return;
}

void Login(vector<Account> *a, vector<Stock> *stonks)
{
    cout<<"Ime: ";
    string im;
    cin>>im;
    cout<<"Acc Number: ";
    int acc;
    cin>>acc;
    cout<<"Password: ";
    string pas;
    cin>>pas;
    cout<<endl;
    ucitajAccounts(a);
    int i=0;
    while(i<a->size())
    {
        if(a->at(i).Login(im,acc,pas)==true){
            Meni_Login(&a->at(i), stonks);
            return;
        }
        i++;
    }
    cout<<"Akaunt ne postoji."<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Registracija"<<endl;
    cout<<"0. Nazad"<<endl;
    int br;
    cin>>br;
    if(br==1)
        Login(a,stonks);
    else if(br==2)
    {
        Registracija(a);
        Login(a,stonks);
    }
    else
        return;

}

void Meni()
{
    cout<<"© 2020 github.com/teofeel All rights reserved"<<endl<<endl;
    vector<Account> accounts;
    vector<Stock> stonks;
    ucitajStocks(&stonks);

    int ulaz;
    do{
        cout<<"*************************************"<<endl;
        cout<<"1. Registracija"<<endl;
        cout<<"2. Prijavljivanje"<<endl;
        cout<<"3. Deonice"<<endl;
        cout<<"4. Marketi (work in progress)"<<endl;
        cout<<"0. Izlaz"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"> ";
        cin>>ulaz;
        switch(ulaz)
        {
        case 1:
            Registracija(&accounts);
            break;
        case 2:
            Login(&accounts,&stonks);
            break;
        case 3:
            izbor_stock(stonks);
            break;
        case 0:
            Kraj_Prograna(&accounts);
            return;
        case 44810:
            Admin_mode(&stonks);
            break;
        default:
            cout<<"Opcija ne postoji. Unesite pomvo"<<endl;
            break;
        }
    }while(ulaz!=0);
}


#endif // FUNKCIJE_HPP_INCLUDED
