#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int i, ret;
    for (i = 0; i <= 2; i++)
    {
        ret = fork();
        if (ret == 0)
        {
            printf("pid=%d ppid=%d\n", getpid(), getppid());
        }
        else
        {
            wait(NULL);
            printf("Parent process with pid= %d\n", getpid());
        }
    }
}
