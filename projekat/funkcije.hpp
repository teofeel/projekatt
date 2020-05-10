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
/*Account Registracija()
{
    Account a;
    cout<<"Ime: "<<endl;
    string i;
    cin>>i;
    a.setIme(i);
    cout<<"Prezime: "<<endl;
    string p;
    cin>>p;
    a.setPrezime(p);
    cout<<"Sifra: "<<endl;
    string pas;
    cin>>pas;
    cout<<"Ponovite sifru: "<<endl;
    string pas1;
    cin>>pas1;
    if(pas1==pas)
        a.setPassword(pas);
    else
        cin pass;

    a.setAcc(rand()%10000000);
    return a;
}
void Meni()
{
   int ulaz;
   cout<<"*************************************"<<endl;
   /*cout<<""
   cout<<""
   cout<<""
   cout<<"*************************************"<<endl;
   do{
    cin>>ulaz;
    switch(ulaz)
    {
    case 1:
    case 0:
        return;
    default:
        cout<<"Opcija ne postoji. Unesite pomvo"<<endl;
    }
   }while(ulaz!=0);
}*/

#endif // FUNKCIJE_HPP_INCLUDED
