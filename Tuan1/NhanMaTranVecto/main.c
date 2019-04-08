#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    int a[10][10], b[10][10], c[10][10];
    int m,n, i, j,k;
    //Nhap ma tran
    printf("Nhap so hang cua ma tran A: ");
    scanf("%d",&m);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d",&n);
    printf("Nhap cac phan tu cua ma tran: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    //coi vecto la mot ma tran cap n hang 1 cot
    printf("Nhap cac phan tu cua vecto: ");
    for(i=0;i<m;i++)
    {
        scanf("%d", &b[i][1]);
    }
    //Phep nhan
    for(i=0;i<m;i++)
    {
            c[i][1]=0;
            for(k=0;k<n;k++)
            {
        c[i][1]+=a[i][k]*b[k][1];
            }
    }
    //in tich matran va vecto
    printf("\nTich cua hai ma tran va vecto la: \n");
    for (i = 0; i < m; i++) {
            printf(" %d ", c[i][1]);
        printf("\n");
    }
}
