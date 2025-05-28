#include <iostream>
using namespace std;
class person
{
private:
    string name,disease;
    int age,billamount;
     
public:
    void setdata(string n, int a,string d,int b,string r)
    {
        name=n;
        age=a;
        disease=d;
        billamount=b;
    }  
    void displaydata()
    {
        cout<<"name0:"<<name<<",\nage:"<<age<<"\ndisease:"<<disease<<"\nbillamount:"<<billamount<<endl;
    }   
};    
int main()
{
    person p1;
    p1.setdata("john doe",45,"pneumonia",3200.5);
    p1.displaydata();
    return 0;
}