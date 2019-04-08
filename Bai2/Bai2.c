#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int a[], int n)
{
    int i,k, tam;
    for (i = 0; i < n-1;i++)
        {
            for (k = i+1; k < n;k++)
            {

                if (a[i]>a[k]) //Tăng dần or Giảm dần a[i]<a[j]
                {
                    tam = a[i];  //k là biến tạm lưu giá trị
                    a[i] = a[k];  //thực hiện đổi chỗ lấy a[j]
                    a[k] = tam;  //thực hiện đổi chỗ lấy a[i]
                }
         }
     }
}
void SelectionSort(int a[], int n)
{
    int vtmin, i, j, tam;
    for(i=0; i<n-1; i++)
    {
        vtmin=i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[vtmin])
                vtmin=j;
        }
        tam=a[i];
        a[i]=a[vtmin];
        a[vtmin]=tam;
    }
}
 void InsertSort(int a[], int n)
 {
    int pos,i, x;
    for(i=1; i<n; i++)
    {
        x=a[i];
        pos=i-1; //Tim vi tri chen x
        while((pos>=0) && (a[pos]>=x))
        {
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x; //Chen x vao day
    }
 }

int main()
{
    int a[20],n, i;
    int chon=0;
    do
    {
        printf("\n");
        printf("\t\t\t =======================Moi_Lua_Chon=======================\n");
        printf("\t\t\t |1. Nhap so phan tu cua mang va Nhap mang                |\n");
        printf("\t\t\t |2. Sap xep tang dan theo thuat toan BubbleSort          |\n");
        printf("\t\t\t |3. Sap xep tang dan theo thuat toan SelectionSort       |\n");
        printf("\t\t\t |4. Sap xep tang dan theo thuat toan InsertSort          |\n");
        printf("Ban chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1:
                printf("Nhap so phan tu cua mang: \n");
                scanf("%d",&n);
                printf("Nhap cac phan tu cua mang: \n");
                for(i=0;i<n;i++)
                {
                    scanf("%d",&a[i]);
                }
                break;
            case 2:
                BubbleSort(a,n);
                printf("Mang sau sap xep: \n");
                for(i=0;i<n;i++)
                {
                    printf("%d",a[i]);
                    printf("\n");
                }
                break;
            case 3:
                SelectionSort(a,n);
                printf("Mang sau sap xep: \n");
                for(i=0;i<n;i++)
                {
                    printf("%d",a[i]);
                    printf("\n");
                }
                break;
            case 4:
                InsertSort(a,n);
                printf("Mang sau sap xep: \n");
                for(i=0;i<n;i++)
                {
                    printf("%d",a[i]);
                    printf("\n");
                }
                break;
            case 5:
                break;
            default:
                printf("Khong co lua chon!\n");
                break;

        }
    }while(chon!=5);
    return 0;
}
