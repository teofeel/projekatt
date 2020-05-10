#ifndef STOCK_HPP_INCLUDED
#define STOCK_HPP_INCLUDED

enum Sector{Tech, Finansije, Medicina, Hemija, Rudarstvo, Prehrana, Nekretnine, Transport, Energetika};

string EnumSector(Sector s)
{
    switch(s)
    {
    case Tech:
        return "Tech";
    case Finansije:
        return "Finansije";
    case Medicina:
        return "Medicina";
    case Hemija:
        return "Hemija";
    case Rudarstvo:
        return "Rudarstvo";
    case Prehrana:
        return "Prehrana";
    case Nekretnine:
        return "Nekretnine";
    case Transport:
        return "Transport";
    case Energetika:
        return "Enenrgetika";
    default:
        return "????";
    }
}

class Stock{
protected:
    string symbol;
    double price;
    int num_shares;
    Sector s;
    double spread;
public:
    Stock()
    {
        symbol="????";
        price=0;
        num_shares=0;
        s=Tech;
        spread=0;
    }
    Stock(string sy, double p, int ns, Sector ss, double sp)
    {
        symbol=sy;
        price=p;
        num_shares=ns;
        s=ss;
        spread=sp;
    }
    Stock(const Stock &st1)
    {
        symbol=st1.symbol;
        price=st1.price;
        num_shares=st1.num_shares;
        s=st1.s;
        spread=st1.spread;
    }

    void setSY(string sy){symbol=sy;}
    void setP(double p){price=p;}
    void setNS(int ns){num_shares=ns;}
    void setS(Sector ss){s=ss;}
    void setSpread(double sp){spread=sp;}

    string getSY()const{return symbol;}
    double getP()const{return price;}
    int getNS()const{return num_shares;}
    Sector getS()const{return s;}
    double getSpread()const{return spread;}

    double getMarketCap()const
    {
        return num_shares*price;
    }
    void Kupi(double spr, int b)
    {
        price=price+spr;
        num_shares=num_shares-b;
    }
    void Prodaj(double spr, int b)
    {
        price=price-spr;
        num_shares=num_shares+b;
    }

    friend void IspisStock(){}

    void pisiTxt(char mode='w')
    {
        ofstream fajl;

        if (mode=='a'){
            fajl.open ("stocks.txt", ios_base::app);
        }
        else{
            fajl.open ("stocks.txt");
        }
        fajl<< symbol <<","<< price <<","<< num_shares <<","<< EnumSector(s) <<","<< spread <<endl;
        fajl.close();
    }

    void citajStocks()
    {
        string linija;
        ifstream fajl ("stocks.txt");
        if (fajl.is_open())
        {
            while ( getline (fajl,linija) )
            {
                cout << linija << '\n';
            }
            fajl.close();
        }

        else
            cout << "Neuspesno otvoren fajl";
    }
};

void IspisStock(const Stock &st)
{
    cout<<"Naziv deonice: "<<st.getSY()<<endl;
    cout<<"Cena: "<<st.getP()<<endl;
    cout<<"Broj izdatih deonica: "<<st.getNS()<<endl;
    cout<<"Trzisna Kapitalizacija: "<<st.getMarketCap()<<endl;
    cout<<"Sektor delatnosti: "<<st.getS()<<endl;
}


#endif // STOCK_HPP_INCLUDED
