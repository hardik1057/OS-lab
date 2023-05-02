#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int count = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *producer(void *arg)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        int item = rand() % 100;
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        buffer[count] = item;
        count++;
        printf("Produced: %d\n", item);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}
void *consumer(void *arg)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex);
        while (count < 5)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        int j;
        for (j = 0; j < 5; j++)
        {
            int item = buffer[j];
            int square = item * item;
            buffer[j] = square;
            printf("Consumed: %d, Squared: %d\n", item, square);
        }
        count = 0;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t producer_thread, consumer_thread;
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    printf("Final buffer: ");
    int i;
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}