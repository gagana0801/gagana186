#include<iostream>
#include<string>
using namespace std;
class booking
{
    public:
    string cname;
    int seats;
    booking(string name = "",int s = 1): cname(name),seats(s){}
    virtual void bookticket()=0;
    virtual ~booking(){}
};
class Flightbooking : public booking
{
    public:
    Flightbooking (string name,int s) : booking(name,s){}
    void bookticket() override
    {
        cout<<" flight ticket bookrd for "<< cname <<" with "<< seats <<" seats "<<endl;
    }
};
class Trainbooking : public booking
{
    public:
Trainbooking (string name,int s) : booking(name,s){}
void bookticket() override
{
    cout<<" train bookedfor "<< cname <<" with "<< seats <<" seats "<<endl;
}
};
class Busbooking : public booking
{
    public:
Busbooking (string name,int s) : booking(name,s){}
void bookticket() override
{
    cout<<" bus  tickets booked for "<< cname <<" with "<< seats <<" seats "<<endl;
}
};
class bookmanager
{
    public:
    void confirmbooking(string name)
    {
        cout<<" booking confirmed for "<<name<<endl;
    }
       void confirmbooking(string name ,int seats)
    {
        cout<< "booking confirmed for "<< name <<" with "<< seats <<" seats(s). "<<endl;
    }
    void confirmbooking(string name ,int seats,string date)
    {
        cout<<" booking confirmed for :  "<< name <<" seats "<< seats <<" date "<<date <<endl;
    }

};
class groupbooking
{
    public:
    int ts;
    groupbooking(int seats=0) : ts(seats){}
    groupbooking operator+(const groupbooking &other)
    {
        return groupbooking(this->ts + other.ts);
    }
    void display()
    {
        cout<<" total froup seats booked "<< ts <<endl;
    }
};
int main()
{
    booking *b1 = new Flightbooking("moltress",2);
    booking *b2 = new Trainbooking("zapdoss",3);
    booking *b3 = new Busbooking("articuno",4);
    cout<<"=== run time polymorphism"<<endl;
    b1->bookticket();
    b2->bookticket();
    b3->bookticket();
     
    cout<<" \n === function overloading === "<<endl;
    bookmanager m;
    m.confirmbooking("totodile");
    m.confirmbooking("cyndaquil",4);
    m.confirmbooking("chikorita",5);

    cout<<" \n === operator overloading=== \n"<<endl;
    groupbooking g1(4);
    groupbooking g2(6);
    groupbooking totalgroup= g1 + g2;
    totalgroup.display();
    delete b1;
    delete b2;
    delete b3;
    return 0;

}
