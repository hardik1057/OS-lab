#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid1 = fork();
    if (pid1 == -1)
    {
        printf("Error creating process\n");
        exit(1);
    }
    else if (pid1 == 0)
    {
        printf("Child 1 (PID: %d) is running\n", getpid());
        while (1)
        {
            sleep(1);
        }
    }
    else
    {
        int pid2 = fork();
        if (pid2 == -1)
        {
            printf("Error creating process\n");
            exit(1);
        }
        else if (pid2 == 0)
        {
            printf("Child 2 (PID: %d) is running\n", getpid());
            exit(0);
        }
        else
        {
            printf("Parent (PID: %d) is running\n", getpid());
            sleep(1);
            printf("Orphaning Child 1 (PID: %d)\n", pid1);
            wait(NULL);
        }
    }
    return 0;
}
