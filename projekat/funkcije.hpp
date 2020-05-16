#ifndef FUNKCIJE_HPP_INCLUDED
#define FUNKCIJE_HPP_INCLUDED

/*void pisiTxt(string nazivFajla, string tekst, char mode='w')
{
    ofstream fajl;

    if (mode=='a'){
        fajl.open (nazivFajla, ios_base::app);
    }
    else{
        fajl.open (nazivFajla);
    }

    fajl << tekst << endl;
    fajl.close();

}

void citajStocks(string NazivFajla)
{
    string linija;
    ifstream fajl (NazivFajla);
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
*/
string PromeniUString(double a)
{
    auto str= to_string(a);
    return str;
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

void ucitajBalance(vector<Balance>* balances)
{
    string linijab;
    vector<string> resultb;
    ifstream fajlb ("balance.txt");
    if(fajlb.is_open())
        {
            while(getline(fajlb,linijab))
            {
                resultb = splitSen(linijab,'|');
                Balance b(promeniUenumV(stoi(resultb[0])),stod(resultb[1]),stoi(resultb[2]),stod(resultb[3]));
                balances->push_back(b);
            }
        }
        else
            cout<<"Neuspesno otvoren fajl"<<endl;
}
void ucitajAccounts(vector<Account>* accounts)
{
        string linija;

        vector<string> result;
        vector<Balance> balances;
        ifstream fajl ("accounts.txt");

        ucitajBalance(&balances);
        if (fajl.is_open())
        {
            int i=0;
            while (getline(fajl,linija))
            {
                if (linija!="")
                {
                    result = splitSen(linija,'|');
                    Account a(result[0], result[1], result[3], stoi(result[2]),balances[i]);
                    accounts->push_back(a);
                }
            }
            fajl.close();
        }

        else
            cout << "Neuspesno otvoren fajl"<<endl;
}
void ucitajStocks(vector<Stock>* stocks)
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

                    Stock s(result[0], stod(result[1]), stoi(result[2]), promeniEnumSec(stoi(result[3])),stod(result[4]));
                    stocks->push_back(s);
                }
            }
            fajl.close();
        }

        else
            cout << "Neuspesno otvoren fajl";
}


void Meni_Login(Account a)
{
    int ulaz;
    do{
        cin>>ulaz;
        cout<<"*************************************"<<endl;
        cout<<"1. Portfolio"<<endl;
        cout<<"2. Balans"<<endl;
        cout<<"3. Kupi"<<endl;
        cout<<"4. Istorija"<<endl;
        cout<<"0. Nazad"<<endl;
        cout<<"*************************************"<<endl;
        cout<<"> ";
        switch(ulaz)
        {
            case 0: return;
            default: cout<<"Opcija ne postoji. Unesite ponovo"<<endl;
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
    Account a(i,p,pas,acc,b);
    a.pisiTxt('a');
    accounts->push_back(a);
    return;
}

void Login(vector<Account> *a)
{

    cout<<"Acc Number: ";
    int acc;
    cin>>acc;
    cout<<endl;
    cout<<"Password: ";
    string pas;
    cin>>pas;
    cout<<endl;
    int i=0;
    while(i<a->size())
    {
        if(a->at(i).Login(acc,pas)==true)
            Meni_Login(a->at(i));
        i++;
    }
    cout<<"Akaunt ne postoji."<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Registracija"<<endl;
    cout<<"0. Nazad"<<endl;
    int br;
    cin>>br;
    if(br==1)
        Login(a);
    else if(br==2)
    {
        Registracija(a);
        Login(a);
    }
    else
        return;

}

void Meni()
{
    cout<<"© 2020 github.com/teofeel & google.com All rights reserved"<<endl<<endl;
    vector<Account> accounts;
    ucitajAccounts(&accounts);
    int ulaz;
    do{
        cout<<"*************************************"<<endl;
        cout<<"1. Registracija"<<endl;
        cout<<"2. Prijavljivanje"<<endl;
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
            Login(&accounts);
            break;
        case 0:
            return;
        default:
            cout<<"Opcija ne postoji. Unesite pomvo"<<endl;
        }
    }while(ulaz!=0);
}

#endif // FUNKCIJE_HPP_INCLUDED
