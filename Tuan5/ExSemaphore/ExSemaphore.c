#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <pthread.h>
#include <semaphore.h>

#define N 120
sem_t mutex;
int count = 0;
void threadSamaphore()
{
    for (count=0;count<=N;count++)
    {
        sem_wait(&mutex);
        printf("Count thread:%d \n",count);
        sem_post(&mutex);
    }
}
int main()
{
    //Cach1();
    int i;
    sem_init(&mutex,0,6);
    pthread_t thread[6];
    for (i=0; i<6; i++)
    {
        pthread_create(&thread[i], NULL, threadSamaphore, NULL);//tạo thread
    }
    for (i=0; i<6; i++)
    {
        pthread_join(thread[i],NULL);
    }
    for (count=0; count<=N; count++)
    {
        printf("%d \n",count);
    }
    return 0;
}
