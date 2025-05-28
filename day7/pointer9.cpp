#include <iostream>
#include <string>
using namespace std;

struct Employee 
{
    string name;
    string shift;
};

int main() {
    int n;

    cout << "Enter the number of employees checked in today: ";
    cin >> n;

    Employee* employees = new Employee[n];

    int morning=0,afternoon=0,night=0;

    for (int i = 0; i < n; ++i)
     {
        cout << "\nEnter details for employee #" << (i + 1) << ":\n ";
        cout<<"Name:";
        cin>>employees[i].name;

        cout << "Enter shift (Morning/Afternoon/Night):";
        cin>>employees[i].shift;

        if(employees[i].shift=="Morning")
        morning++;
        else if(employees[i].shift=="Afternoon")
        afternoon++;
        else if(employees[i].shift=="Night")
        night++;
     }

     cout<<"\n=========Employee Shift LIst==========\n";
     for(int i=0; i<n; i++)
     {
        cout<<(i+1)<<"."<<employees[i].name
            <<"-"<<employees[1].shift<<"shift"<<endl;
     }

     cout<<"\n==========Shift Summer=========\n";
     cout<<"Morning Shift:"<<morning<<endl;
     cout<<"Afternoon Shift:"<<afternoon<<endl;
     cout<<"Night Shift:"<<night<<endl; 

     delete[]employees;
     return 0;
    }