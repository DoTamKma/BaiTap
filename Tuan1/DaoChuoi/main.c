#include <conio.h>
#include <stdio.h>
#include <string.h>  //thư viện chuỗi

int main()
{
    char str[30];
    printf("Nhap vao 1 chuoi: ");
    gets(str);
    printf("Chuoi duoc dao nguoc la: ");
    for(int i=strlen(str)-1;i>=0;i--)  //strlen trả về độ dài của chuỗi
    {
        printf("%c",str[i]);
    }
    getch();
}
