#include <stdio.h>
#include <stdlib.h>

void main()
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
