#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of students:";
    cin>>n;
    string*names=new string[n];
    cout<<"enter student name:";
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<",";
        cin>>names[i];
    }
    char choice;
    do
  {
    string key;
    cout<<"enter the name to search:";
    cin>>key;
    bool found=false;
    for(int i=0; i<n; i++)
    {
        if(names[i]==key)
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
    cout<<"do you want to search again(y/n)?";
    cin>>choice;
  }while(choice=='y'||choice=='y');
    delete[]names;
    return 0;
}