#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int i;
    for (int i = 0; i < 3; i++)
    {
        int ret = fork();
        if (ret == 0)
        {
            printf("\nPid of child- %d, it's parent= %d\n", getpid(), getppid());
            break;
        }
        else
        {
            printf("\nProcess id of parent= %d\n", getpid());
        }
    }
    return 0;
}

