#include <iostream>
using namespace std;
class product
{
private:
   string name;
   double price;
public:
   product(string name, double price)
   {
    this->name=name;
    this->price=price;
   }
   void display()
   {
    cout<<"product:"<<this->name<<",price: $"<<this->price<<endl;
   }       
};
int main()
{
    product p1("laptop", 999.99);
    product p2("smartphone", 490.49);
    p1.display();
    p2.display();
    return 0;
}