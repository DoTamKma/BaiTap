#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    s[0]='\0';
    printf("Nhap vao chuoi:",s);
    gets(s);
    char *p;
//    int vitri;

    p= strstr(s,"sdf");
  //  vitri=(p-s+1);
    if(p!=NULL)
    {
        strncpy(p,"",3);
        printf("Chuoi sau xoa: %s",s);
    }
    else
        printf("Khong tim thay chuoi");
   // int i,j;
    return 0;
}
