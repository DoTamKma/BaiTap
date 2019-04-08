#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i;
    char s[100];
    printf("nhap chuoi bat ky chua chuan hoa:");
    gets(s);
    fflush(stdin);// xoa vung đệm bàn phím trước hàm nhập chuỗi
    // xoa ki tu trang o dau xau
    while (s[0]==' ')
    strcpy(&s[0],&s[1]);// xoa ki tu chua dau cach
    // xoa ki tu trang o cuoi xau
    while (s[strlen(s)-1]==' ')
    strcpy(&s[strlen(s)-1],&s[strlen(s)]);//xoa ki tu chua dau cach
    //xoa ki tu trang thua o giua xau
    for(i=0; i<strlen(s) ;i++)
    if ((s[i]==' ') && s[i]=&&(s[i+1]==' '))
    {
    strcpy(&s[i],&s[i+1]);
    i--;
    }
    //thêm dau cach sau dau phay

    printf("xau da chuan hoa: \"%s\"",s);

    getch();
}
/*

Int islower(int c): kiểm tra ký tự có là chữ thường không.
Int isupper(int c): kiểm tra ký tự có là chữ hoa không
Int ispace(int c): kiểm tra ký tự có là trống không (\n, dấu cách, \t)
Int strlen(char *s) trả về độ dài của xâu s;
Char *strupr(char *s) đổi chữ thường trong xâu s sang chữ hoa.
Char *strlwr(char *s) đổi chữ hoa sang chữ thường.
Char *strcat(char *s1, char *s2) nối xâu s2 vào xâu s1;
Int strcmp(char *s1, char *s2) cho giá trị âm nếu xâu s1 nhở hơn xâu s2. Và cho giá tị dương nếu xâu s1 lớn hơn xâu s2. Trả về giá trị bằng 0 nếu xâu s1 bằng xâu s2.
Int strcmpi (char *s1, char *s2) so sánh 2 xâu nhưng không phân biệt chữ thường và chữ hoa.
Char *strcpy(char *s1, char *s2) copy xâu s2 vào xâu s1.
Char *strncpy(char *s1, char *s2, int n) sao chép n ký tự đầu của xâu s2 sang xâu s1
Char *strnset(char *s ,int c, int n) dùng để sao chép n lần ký tự c vào xâu s.
Char *strstr(char *s1, char *s2) tìm sự xuất hiện của xâu s2 trong xâu s1. Nếu tìm thấy hàm cho địa chỉ của xâu con trong xâu s1. Trái lại cho NULL.
Char *strrev(char *s) dùng đảo ngược xâu s.Nếu thành công hàm cho địa chỉ xâu đã đảo.
*/
