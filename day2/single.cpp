#include <iostream>
using namespace std;
class animal
{
public:
    void speak()
    {
        cout<<"animal speaks"<<endl;
    } 
};      
    class dog:public animal
    {
       public:
       void bark()
       {
            cout<<"dog barks"<<endl;
       }
    };
    int main()
    {
        dog d; 
        d.speak();
        d.bark();
        return 0;
    }
