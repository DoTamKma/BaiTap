#include <stdio.h>
#include <string.h>
#include <conio.h>

int demchuhoa(char s[])
{
       int i,dem=0;
       for (i=0;i<strlen(s);i++)
        if ( s[i]>='A' && s[i]<='Z' )
                     dem++;
       return dem;
}
int demchuthuong(char s[])
{
       int i,dem=0;
       for (i=0;i<strlen(s);i++)
        if ( s[i]>='a' && s[i]<='z' )
                     dem++;
       return dem;
}
int main()
{
    char s[100];
    printf("\nNhap mot chuoi bat ky:");
    gets(s);
    printf("So ki tu viet hoa la  :  %d\n",demchuhoa(s));
    printf("So ki tu viet thuong la: %d",demchuthuong(s));
    getch();
}
