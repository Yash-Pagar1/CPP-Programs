#include<iostream>
using namespace std;

int Addition(int No1, int No2)
{
    int Ans = 0;
    Ans = No1 + No2;
    return Ans;
}
int main()
{
    int a = 10, b = 11, iRet = 0;

    iRet = Addition(a, b);

    cout << "Addition is : " << iRet <<"\n";

    return 0;
}