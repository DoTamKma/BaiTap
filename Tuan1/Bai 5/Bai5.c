#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
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
