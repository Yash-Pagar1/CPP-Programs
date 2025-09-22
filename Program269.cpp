#include<iostream>
using namespace std;

int main()
{
    int iValue = 0;

    cout<<"Enter Number : \n";
    cin>> iValue;

    cout<<"Number in Decimal Format is : "<<std::dec<<iValue<<"\n";
    cout<<"Number in Octal Format is : "<<std::oct<<iValue<<"\n";
    cout<<"Number in HexaDecimal Format is : "<<std::hex<<iValue<<"\n";
    
    return 0;
}