#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of students:";
    cin>>n;
    int*rollnumber=new int[n];
    cout<<"enter student rollnumber:";
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<",";
        cin>>rollnumber[i];
    }
    int key;
    cout<<"enter the rollnumber to search:";
    cin>>key;
    bool found=false;
    for(int i=0; i<n; i++)
    {
        if(rollnumber[i]==key)
        {
            cout<<"student"<<key<<"found at position"<<i+1<<endl;
            found=true;
            break;
        }
    }
    if(!found)
    {
        cout<<"student"<<key<<"not found in list."<<endl;
    }
    delete[]rollnumber;
    return 0;
}