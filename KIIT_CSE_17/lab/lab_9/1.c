#include <pthread.h>
#include <stdio.h>
int shared = 0;
pthread_mutex_t mutex;
void *thread_start()
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);//
        shared++;
        pthread_mutex_unlock(&mutex);//
    }
}
int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);//
    pthread_create(&t1, NULL, thread_start, NULL);
    pthread_create(&t2, NULL, thread_start, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);//
    printf("Value of shared variable %d ", shared);
    return 0;
}