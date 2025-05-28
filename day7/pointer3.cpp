#include <iostream>
using namespace std;
void displayBedOccupancy(int*patientIDs, int*bedIDs, int size)
{
    cout<<"hospital bed occupy:\n";
    for(int i=0; i<size; i++)
    {
        cout<<"bed ID:"<<*(bedIDs+i)<<"|patient ID:"<<*(patientIDs+i)<<endl;
    }
    cout<<endl;
}
int main() {
    const int SIZE=5;
    int bedIDs[SIZE]={201, 202, 203, 204, 205};
    int patientIDs[SIZE]={101, 102, 103, 104, 105};
    int*ptrpatient=patientIDs;
    int*ptrbed=bedIDs;
    displayBedOccupancy(ptrpatient, ptrbed, SIZE);
    *(ptrpatient+2)=100;
    displayBedOccupancy(ptrpatient, ptrbed, SIZE);
    return 0;
}