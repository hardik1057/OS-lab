#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;

    printf("Parent process, pid = %d\n", getpid());

    if ((pid = fork()) == 0)
    {
        printf("Child process c1, pid = %d, parent pid = %d\n", getpid(), getppid());

        if ((pid = fork()) == 0)
        {
            printf("Child process c2, pid = %d, parent pid = %d\n", getpid(), getppid());

            if ((pid = fork()) == 0)
            {
                printf("Child process c3, pid = %d, parent pid = %d\n", getpid(), getppid());
                exit(0);
            }

            wait(NULL);
            exit(0);
        }

        wait(NULL);
        exit(0);
    }

    wait(NULL);

    printf("All child processes completed. Exiting...\n");
    return 0;
}
