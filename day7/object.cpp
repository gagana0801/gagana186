#include <iostream>
using namespace std;
class dog
{
public:
   void bark()
   {
        cout<<"woof!"<<endl;
   }    
};
int main()
{
    dog*d=new dog();
    d->bark();
    delete d;
    return 0;
} 