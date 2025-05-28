#include <iostream>
#include <string>
using namespace std;
class vehicle
{
private:
     string model;
     int year;
public:
   vehicle(string m, int y)
   {
       model=m;
       year=y;
   }         
   void show()
   {
        cout<<"model:"<<model<<",year"<<year<<endl;
   }
};
int main()
{
    vehicle*v1=new vehicle("toyota camry",2022);
    vehicle*v2=new vehicle("tesla model",2023);
    v1->show();
    v2->show();
    delete v1;
    delete v2;
    return 0;
    
}
