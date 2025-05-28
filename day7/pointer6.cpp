#include <iostream>
using namespace std;
class product
{
private:
   string name;
   double price;
   int discount;
public:
   product(string name, double price, int discount)
   {
    this->name=name;
    this->price=price;
    this->discount=discount;
   }
   void display()
   {
    cout<<"product:"<<this->name<<",price: $"<<this->price<<"discount:%"<<endl;
   }       
};
int main()


{
    product p1("laptop", 999.99);
    product p2("smartphone", 490.49);
    product.setdiscount(10);

    p1.display();
    p2.display();
    return 0;
}