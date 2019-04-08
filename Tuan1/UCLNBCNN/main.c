#include <stdio.h>
#include <stdlib.h>

int UCLN(int a, int b)
{
    if(a==b)
    {
        return a;
    }
    else
    {
        if(a>b)
        {
            UCLN(a-b,b);
        }
        else
        {
            UCLN(b-a,a);
        }
    }
}
int BCNN(int a, int b)
{
    int tich=a*b;
    return tich/UCLN(a,b);
}
int main()
{
    int a, b;
    printf("Moi nhap so a: ");
    scanf("%d",&a);
    printf("Moi nhap so b: ");
    scanf("%d",&b);
    printf("UCLN cua hai so la: %d", UCLN(a,b));
    printf("\nBCNN cua hai so la: %d", BCNN(a,b));
    return 0;
}
