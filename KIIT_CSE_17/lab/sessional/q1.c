// write a c program that will create two threads using pthread library. the first thread will generate random integer and puta them into a shared bufffer
// . the second, theread starts reading from the buffer only whe nthe buffer is haf filled and then calculates the square of the number and updatet the same
//  into the buffer. apply the mutex lock to avoid daat inconsistency during the read write operation to the shared buffer. funally pprint the updated buffer 
//  in the main process
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
int shared_value[10];
pthread_t t1, t2;
pthread_mutex_t mutex;
void *threadstart()
{
    int z;
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        z = i;
        printf("Enter value ");
        scanf("%d", &shared_value[i]);
        printf("\n");
        pthread_mutex_unlock(&mutex);
    }
    if (z >= 4)
    {
        for (int j = 0; j <= z; j++)
        {
            pthread_mutex_lock(&mutex);
            shared_value[j] = shared_value[j] * shared_value[j];
            pthread_mutex_unlock(&mutex);
        }
    }
}
int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, threadstart, NULL);
    pthread_create(&t2, NULL, threadstart, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    for (int k = 0; k < 10; k++)
    {
        printf("%d  ", shared_value[k]);
    }
}
