#include <iostream>
using namespace std;
class name
{
public:
    void start()
    {
        cout<<"vehicle has started."<<endl;
    } 
};      
    class car:public vehicle
    {
       public:
       void drive()
       {
            cout<<"car is driving."<<endl;
       }
    };
    int main()
    {
        car mycar;
        mycar.start();
        mycar.drive();
        return 0;
    }
