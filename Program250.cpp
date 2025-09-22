#include<iostream>
using namespace std;

float Addition(float No1, float No2)
{
    float Ans;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    float Ret, Value1, Value2;

    cout<<"Enter First number : \n";
    cin>>Value1;

    cout<<"Enter Second number : \n";
    cin>>Value2;

    Ret = Addition(Value1, Value2);

    cout<<"Addition is : "<<Ret<<"\n";
    
    return 0;
}