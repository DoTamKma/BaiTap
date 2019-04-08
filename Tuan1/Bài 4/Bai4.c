#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,h;
    printf("Moi nhap chieu cao tam giac: ");
    scanf("%d",&h);

    for(i=0;i<h;i++)
    {
        for(j=0;j<h+i;j++)
        {
            if(j<h-1-i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}
