#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
int randomNumber()
{
    int i;
    FILE *fi;
    fi = fopen("D:/TÁM/Tuan4/number.txt","wt");
    for(i=0;;i++)
    {
        Sleep(2);
        int random = rand()%30;
        fprintf(fi,"%d",random);
    }
    fclose(fi);
    printf("Hoan thanh thread 1.\n");
}
int TinhBinhPhuong(int n)
{
    int bphuong;
    bphuong = n*n;
    return bphuong;
}
int docGhiFile()
{
    FILE *fo;
    int n,i;
    fo = fopen("D:/TÁM/Tuan4/number.txt","rt");
    for(i=0;;i++)
    {
        Sleep(1);
        fscanf(fo,"%5d",&n);
        TinhBinhPhuong(n);
    }
    fclose(fo);
    fo= fopen("D:/TÁM/Tuan4/output.txt", "wt");
    for(i=0;;i++)
    {
        Sleep(1);
        fscanf(fo,"%5d",&n);
        fscanf(fo,"%5d",TinhBinhPhuong);
    }
    fclose(fo);
    printf("Hoan thanh thread 2.\n");
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    int res;
    res = pthread_create(&thread1, NULL, randomNumber, NULL);

    if(res!=0)
    {
        printf("Error!!\n");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&thread2, NULL, docGhiFile, NULL);
    if(res!=0)
    {
        printf("Error!!\n");
        exit(EXIT_FAILURE);
    }
    printf("Waitting for the thread to end...\n");
    pthread_join(thread1, NULL);
    printf("Thread ended\n");

    return 0;
}
