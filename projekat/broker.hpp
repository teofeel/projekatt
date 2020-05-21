#ifndef BROKER_HPP_INCLUDED
#define BROKER_HPP_INCLUDED
#include <string>

class Broker{
private:
    string name;
    string server_name;
    double spread;
public:
    Broker()
    {
        name="????";
        server_name="Server";
        spread=0;
    }
    Broker(string n, string sn, double sp)
    {
        name=n;
        server_name=sn;
        spread=sp;
    }
    Broker(Broker *b)
    {
        name=b->name;
        server_name=b->server_name;
        spread=b->spread;
    }
    Broker(const Broker &b)
    {
        name=b.name;
        server_name=b.server_name;
        spread=b.spread;
    }
    void setName(string n){name=n;}
    void setSN(string sn){server_name=sn;}
    void setSpread(double sp){spread=sp;}

    string getName()const{return name;}
    string getSN()const{return server_name;}
    double getSpread()const{return spread;}

    void pisiTxt(char mode='w')
    {
        ofstream fajl;

        if (mode=='a'){
            fajl.open ("broker.txt", ios_base::app);
        }
        else{
            fajl.open ("broker.txt");
        }
        fajl<< name <<"|"<< server_name <<"|"<< spread <<endl;
        fajl.close();
    }

    void citajBroker()
    {
        string linija;
        ifstream fajl ("broker.txt");
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
    ~Broker();
};
Broker::~Broker(){}

#endif // BROKER_HPP_INCLUDED
