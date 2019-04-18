#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\Lib\DemSoKyTu.h"
#include "..\Lib\UCLNBCNN.h"
#include "..\Lib\Bai1_DSLK.h"

int i;
void Bai1_Tuan1()
{
    int n, a, b, c, doi;
    printf("Nhap so nguyen bat ky(gom 3 chu so): ");
    scanf("%d", &n);
    a = n/100;
    b = ((n%100)/10);
    c = n%10;
    if(a<b)
     {
      doi=a;
      a=b;
      b=doi;
     }
    if(b<c)
     {
     doi=b;
     b=c;
     c=doi;
     }
    if(a<b)
     {
     doi=a;
     a=b;
     b=doi;
     }
    printf("%d%d%d", a, b, c);
}
void Bai2_Tuan1()
{
    char s[100];
    int demchuhoa(s);
    int demchuthuong(s);
    printf("\nNhap mot chuoi bat ky:");
    gets(s);
//    printf("So ki tu viet hoa la  :  %d\n",demchuhoa(s));
//   printf("So ki tu viet thuong la: %d",demchuthuong(s));
    getch();
}
void Bai3_Tuan1()
{
    float sokm=0;
	float sotien = 0;
	printf("Nhap so km da di:");
	scanf("%f",&sokm);
	if (sokm <30 && sokm >1){
		sotien = 10000+(sokm-1)*7500;
	}
		else if (sokm > 30)
			{
					sotien = 10000+29*7500+(sokm - 30)*8000;
	                }
	printf("so tien phai tra la: %0.2f\n",sotien);
}
void Bai4_Tuan1()
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
void Bai5_Tuan1()
{
    int ngay, thang, nam;
    printf("Nhap ngay: ");
    scanf("%d",&ngay);

    printf("Nhap thang: ");
    scanf("%d", &thang);

    printf("Nhap nam: ");
    scanf("%d",&nam);

    switch(thang)
    {
        case 1: case 3: case 5: case 7: case 8: case 10:  case 12:
            if( ngay>0 && ngay<=31)
                {
                    printf("Ngay %d thang %d nam %d hop le\n",ngay,thang,nam);
                    break;
                }
            else
                {
                    printf("Khong hop le\n");
                    break;
                }
        case 4: case 6: case 9: case 11:
            if( ngay<=30 && ngay>0)
                {
                    printf("Ngay %d thang %d nam %d hop le\n",ngay,thang,nam);
                    break;
                }
            else
                {
                    printf("Khong hop le\n");
                    break;
                }
        case 2:
            if
                (
                    ngay <=28 && ngay > 0)
                    {
                        printf("Ngay %d thang %d nam %d hop le\n",ngay,thang,nam);
                        break;
                    }
            else
                    {
                        printf("Khong hop le\n");
                        break;
                    }
        default: printf("Ngay %d thang %d nam ko hop le\n",ngay,thang,nam);
        break;

    }
    printf("\n");
//Kiem tra nam nhuan
    if (((nam % 4 == 0) && (nam % 100!= 0)) || (nam%400 == 0))
        printf("%d la mot nam nhuan", nam);
    else
        printf("%d khong phai la nam nhuan", nam);
}
void Bai6_Tuan1()
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
    /*for(i=0; i<strlen(s);i++)
    {
        if ((s[i]=='  ') && s[i]=&&(s[i+1]=='  '))
        {
            strcpy(&s[i],&s[i+1]);
            i--;
        }
    }*/

    //thêm dau cach sau dau phay

    printf("xau da chuan hoa: \"%s\"",s);

    getch();
}
void Bai7_Tuan1()
{
    int a, b;
    printf("Moi nhap so a: ");
    scanf("%d",&a);
    printf("Moi nhap so b: ");
    scanf("%d",&b);
//    printf("UCLN cua hai so la: %d", UCLN(a,b));
    //printf("\nBCNN cua hai so la: %d", BCNN(a,b));
    return 0;
}

void Bai8_Tuan1()
{
    char str[30];
    printf("Nhap vao 1 chuoi: ");
    gets(str);
    printf("\nChuoi duoc dao nguoc la: ");
    for(int i=strlen(str)-1;i>=0;i--)  //strlen trả về độ dài của chuỗi
    {
        printf("%c",str[i]);
    }
    getch();
}
void Bai9_Tuan1()
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
void Bai10_Tuan1()
{
char s[100];
    s[0]='\0';
    printf("Nhap vao chuoi:\n",s);
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
void Bai1a_Tuan2()
{
    node head;
    int x, y, pos;
    int a=0;
    do
    {
        printf("\n");
        printf("\t\t\t =======================Moi_Lua_Chon===============\n");
        printf("\t\t\t |1. Nhap danh sach                               |\n");
        printf("\t\t\t |2. Them phan tu vao danh sach lien ket          |\n");
        printf("\t\t\t |3. Sua phan tu trong danh sach lien ket         |\n");
        printf("\t\t\t |4. Xoa phan tu trong danh sach lien ket         |\n");
        printf("\t\t\t |5. Lay so luong phan tu trong danh sach         |\n");
        printf("Ban chon: ");
        scanf("%d", &a);
        /*switch(a)
        {
            case 1:
                head=Nhap();
                In(head);
                break;
            case 2:
                printf("Nhap gia tri can them: ");
                scanf("%d",&x);
                head=ThemPhanTu(head,x);
                In(head);
                break;
            case 3:
                head= SuaPhanTu(head);
                In(head);
                break;
            case 4:
                //printf("Nhap vi tri muon xoa: \n");
                //scanf("%d",pos);
                head= XoaPhanTu(head, pos);
                In(head);
                break;
            case 5:
                head= LaySoPhanTu(head);
                break;
            case 6:
                break;
            default:
                printf("Khong co lua chon!\n");
                break;

        }*/
    }while(a!=6);
    return 0;
}
void Bai1b_Tuan2()
{

}
void Bai1c_Tuan2()
{

}
void Bai2_Tuan2()
{
    int i, k, tam;
    int a[20],n;
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

     int vtmin, j;
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

    int pos, x;
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

    printf("Nhap so phan tu cua mang: \n");
    scanf("%d",&n);
    printf("Nhap cac phan tu cua mang: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Mang sau sap xep: \n");
                for(i=0;i<n;i++)
                {
                    printf("%d",a[i]);
                    printf("\n");
                }
}
void Bai3_Tuan2()
{

}
void Bai4_Tuan2()
{
    int n,i,j;
    printf("nhap vao so tu nhien N:");
    scanf("%d",&n);
    if(n<2 || n>5)
    {
        printf("ban da nhap sai moi ban nhap lai:");
        scanf("%d",&j);
        for(i=0; i<pow(10,j); i++)
        {
            if(i%11==0)
                printf("\n%d",i);
        }
    }
    else
        for(i=0; i<pow(10,n); i++)
        {
            if(i%11==0)
                printf("\n%d",i);
        }
    getch();
}
void Bai1_Tuan3()
{

}
int main()
{
    int chon;

    do
    {
        printf("\n");
        printf("\t\t\t =======================Moi_Lua_Chon=======================\n");
        printf("\t\t\t |1. Bai1_Tuan1                                           |\n");
        printf("\t\t\t |2. Bai2_Tuan1                                           |\n");
        printf("\t\t\t |3. Bai3_Tuan1                                           |\n");
        printf("\t\t\t |4. Bai4_Tuan1                                           |\n");
        printf("\t\t\t |5. Bai5_Tuan1                                           |\n");
        printf("\t\t\t |6. Bai6_Tuan1                                           |\n");
        printf("\t\t\t |7. Bai7_Tuan1                                           |\n");
        printf("\t\t\t |8. Bai8_Tuan1                                           |\n");
        printf("\t\t\t |9. Bai9_Tuan1                                           |\n");
        printf("\t\t\t |10. Bai10_Tuan1                                         |\n");
        printf("\t\t\t |11. Bai1.1_Tuan2                                        |\n");
        printf("\t\t\t |12. Bai1.2_Tuan2                                        |\n");
        printf("\t\t\t |13. Bai1.3_Tuan2                                        |\n");
        printf("\t\t\t |14. Bai2_Tuan2                                          |\n");
        printf("\t\t\t |15. Bai3_Tuan2                                          |\n");
        printf("\t\t\t |16. Bai4_Tuan2                                          |\n");
        printf("\t\t\t |17. Calculator_Tuan3                                    |\n");

        printf("Ban chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1:
                Bai1_Tuan1();
                break;
            case 2:
                Bai2_Tuan1();
                break;
            case 3:
                Bai3_Tuan1();
                break;
            case 4:
                Bai4_Tuan1();
                break;
            case 5:
                Bai5_Tuan1();
                break;
            case 6:
                Bai6_Tuan1();
                break;
            case 7:
                Bai7_Tuan1();
                break;
            case 8:
                Bai8_Tuan1();
                break;
            case 9:
                Bai9_Tuan1();
                break;
            case 10:
                Bai10_Tuan1();
                break;
            case 11:
                Bai1a_Tuan2();
                break;
            case 12:
                Bai1b_Tuan2();
                break;
            case 13:
                Bai1c_Tuan2();
                break;
            case 14:
                Bai2_Tuan2();
                break;
            case 15:
                Bai3_Tuan2();
                break;
            case 16:
                Bai4_Tuan2();
                break;
            case 17:
                Bai1_Tuan3();
                break;
            case 18:
                break;
            default:
                printf("Lua chon sai!\n");
                break;

        }
    }while(chon!=18);
    return 0;
}
