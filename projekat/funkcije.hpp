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





#endif // FUNKCIJE_HPP_INCLUDED
