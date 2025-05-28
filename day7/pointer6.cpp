#include <iostream>
using namespace std;
class product
{
   private:
       string name;
       double price;
       double discount;
   public:
      product(string name, double percent)
     {
         this->name=name;
         this->price=price;
         this->discount=0.0;
     }
     product &setdiscount(double percent)
     {
        this->discount=percent;
        return*this;
     }
     double getfinalprice() const
     {
       return price-(price*discount/100.0);
     }
    bool operator>(const product &other) const
    {
      return this->getfinalprice()>other.getfinalprice();
    }
    void show() const
    {
         cout<<"product:"<<name
         <<"<original price:$"<<price
         <<",discount:"<<discount
         <<",final price:4"<<getfinalprice()
         <<endl;
    }       
};
int main()
{
    product laptop("Laptop", 1200.00);
    product tablet("Tablet", 900.00);
    laptop.setdiscount(15).show();
    tablet.setdiscount(5).show();
    if(laptop>tablet)
    {
      cout<<laptop.getfinalprice()<<"is more expensive than"<<tablet.getfinalprice()<<endl;
    }
    else
    {
      cout<<tablet.getfinalprice()<<"is more expensive than"<<laptop.getfinalprice()<<endl;
    }
    return 0;
   }     