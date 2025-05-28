#include <iostream>
using namespace std;
class camera
{
public:
   void takePhoto()
   {
    cout<<"taking a photo..."<<endl;
   }    
};
class phone
{
public:
    void makeCall()
    {
        cout<<"making a call..."<<endl;
    }    
};
class smartphone:public camera,public phone
{
public:
   void browseInternet()
   {
    cout<<"browsing Internet..."<<endl;
   }       
};
int main()
{
    smartphone s;
    s.takePhoto();
    s.browseInternet();
    return 0;
}