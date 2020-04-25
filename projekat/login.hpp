#ifndef LOGIN_HPP_INCLUDED
#define LOGIN_HPP_INCLUDED
#include "account.hpp"
class Login{
private:
    Account a;
    string password="password";

public:
    Login(const Account &acc,string lg):a(acc)
    {
        lg="\0";
    }
    bool Tacno();
};
bool Login :: Tacno()
{
    string pass;
    cin >>pass;
    int accn;
    cin >>accn;
    if(pass=password && accn=a.getAcc())
    {
        return true;
    }
    else
        return false;
}
#endif // LOGIN_HPP_INCLUDED
