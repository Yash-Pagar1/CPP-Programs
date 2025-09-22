#include<iostream>
using namespace std;

template <class T>
T Addition(T No1, T No2)
{
    T Ans;
    Ans = No1 + No2;
    return Ans;
}

int main()
{
    cout<<Addition(10,11)<<"\n";
    cout<<Addition(10.20f, 11.40f)<<"\n";
    cout<<Addition(10.40,11.60)<<"\n";
    
    return 0;
}
