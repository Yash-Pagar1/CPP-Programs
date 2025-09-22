#include<stdio.h>

int main()
{
    int iValue = 0;

    printf("Enter the Number : \n");
    scanf("%d",&iValue);

    printf("Number in Decimal Format is : %d\n",iValue);
    printf("Number in Octal Format is : %o\n",iValue);
    printf("Number in HexaDecimal Format is : %x\n",iValue);

    return 0;
}