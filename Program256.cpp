#include<iostream>
using namespace std;

int main()
{
    int Size;

    cout<<"Enter the elements : \n";
    cin>>Size;

    int *ptr = new int[Size];

    //Use

    delete []ptr;

    return 0;
}