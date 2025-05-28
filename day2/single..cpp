#include <iostream>
using namespace std;
class user
{
public:
    string name, email;
    void login()
    {
        cout<<name<<"logged in with email"<<email<<endl;
    }
};      
    class customer:public user
    {
       public:
       void browseProducts()
       {
            cout<<name<<"is browsing Prouducts"<<endl;
       }
    };
    int main()
    {
        customer c;
        c.name="alice";
        c.email="alice@example.com";
        c.login();
        c.browseProducts();
        return 0;
    }
