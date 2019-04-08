#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fi = fopen("","r");
    FILE *fo = fopen("","w");

    // Nhap du lieu tu file input
    fscanf(fi, "%d %d %d %d",&n, &m,&u,&v);
    int A[2][m];


    //Nhập số tuyến đường từng cặp 1
    for(int i =0;i<2;i++)
    {
        for(int j=0;i<m;j++)
        {
            fscanf(fi,"%d",&A[i][j]);
        }
    }
    //Tim duong di tu dinh 1 den dinh 7

}
