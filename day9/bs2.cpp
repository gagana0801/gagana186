#include  <iostream>
using namespace std;
int binarysearch(int arr[], int size, int key)
{
    int left=0, right=size-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
            if(arr[mid]==key)
        return mid;
        else if(arr[mid]<key)
             left=mid+1;
        else
             right=mid-1;
    }
    return -1;
}
void displaybooks(int arr[], string titles[], int size)
{
    cout<<"\n available books:\n";
    for(int i=0; i<size; i++)
    {
        cout<<"id:"<<arr[i]<<"-"<<titles[i]<<endl;
    }
}
int main() 
{
    const int size=7;
    int bookids[size]={1001,1005,1010,1020,1030,1050,1100};
    string booktitles[size]={
        "c++ basics","data strucutre","algorithms","database systems",
        "operating system","computer networks","ai fundamentals"};
        displaybooks(bookids,booktitles,size);
        int searchid;
        cout<<"\n enter the bookid to search:";
        cin>>searchid;
        int index=binarysearch(bookids,size,searchid);
        if(index!=-1)
        {
            cout<<"book found:"<<booktitles[index]
            <<"(id:"<<bookids[index]<<")"<<endl;
    }
    else
    {
        cout<<"book with id"<<searchid<<"not found."<<endl;
    }
    return 0;
}    
