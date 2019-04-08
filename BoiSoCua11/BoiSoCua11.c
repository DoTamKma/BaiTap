#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int DemChuSo(int boiso)
{
    int dem=0;
    while(boiso>=10){
        boiso=boiso/10;
        dem++;
    }
    return dem+1;
}
int main()
{
    int n;
    int i, dem;
    int boiso=0;
    printf("Nhap so nguyen n: ");
    scanf("%d",&n);
    if(n>=2 && n <=5)
    {
        printf("So n thoa man!!\n");
        for(i=1;i<=9090;i++)
        {
            boiso= 11*i;
            if(DemChuSo(boiso)<=n)
            {
                printf("Boi so la %d\n", boiso);
            }
        }
    }
    else
    {
        printf("\t\tNhap sai! Moi nhap so n nam trong khoang 2 den 5!!\n");
    }

    return 0;
}
