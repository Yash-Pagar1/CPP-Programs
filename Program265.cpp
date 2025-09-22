#include<iostream>
using namespace std;

int Countzero(int iNo)
{
    int iDigit = 0;
    int iCount = 0;

    while(iNo != 0)
    {
        iDigit = iNo % 2;
        if(iDigit == 0)
        {
            iCount++;
        }
        iNo = iNo / 2;
    }
    return iCount;
}
int main()
{
    int iValue = 0, iRet = 0;

    cout<<"Enter the number : \n";
    cin>>iValue;

    iRet = Countzero(iValue);

    cout<<"Number of  0 : "<<iRet<<"\n";
    
    return 0;
}