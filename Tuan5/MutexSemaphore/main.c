#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define N 10

sem_t semaphore;
pthread_mutex_t mutex;
int count = 0;

void Samaphore()
{
    for (count=0;count<=N;count++)
    {
        sem_wait(&semaphore);
        printf("Count thread semaphore:%d \n",count);
        sem_post(&semaphore);
    }
}
void Mutex()
{
    for (count=0;count<=N;count++)
    {
        pthread_mutex_lock( &mutex);
        printf("Count thread mutex:%d \n",count);
        pthread_mutex_unlock( &mutex);
    }
}
int main()
{
    int i;
    sem_init(&semaphore,0,6);
    pthread_t thread[6];
    //Semaphore
    printf("Example Semaphore: ");
    for (i=0; i<6; i++)
    {
        pthread_create(&thread[i], NULL, Samaphore, NULL);//tao thread
    }
    for (i=0; i<6; i++)
    {
        pthread_join(thread[i],NULL);
    }
    // Mutex
    printf("Example Mutex: ");
     for (i=0; i<6; i++)
    {
        pthread_create(&thread[i], NULL, Mutex, NULL);//tao thread
    }
    for (i=0; i<6; i++)
    {
        pthread_join(thread[i],NULL);
    }
    return 0;
}
