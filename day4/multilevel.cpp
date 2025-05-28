#include <iostream>
using namespace std;
class animal
{
    public:
    void breathe()
    {
        cout<<"animal breathing..."<<endl;
    }
};
class mammal:public animal
{
    public:
    void feedmilk()
    {
        cout<<"mammal feeding milk to babies."<<endl;
    }
};
class dog:public mammal
{
    public:
    void bark()
    {
        cout<<"dog barking!"<<endl;
    }
};
int main()
{
    dog d;
    d.breathe();
    d.feedmilk();
    d.bark();
    return 0;
}