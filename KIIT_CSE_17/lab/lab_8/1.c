#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int fd[2];
    pipe(fd);
    int ret1 = fork();
    if (ret1 == 0)
    {
        // child 1
        dup2(fd[1], 1);
        system("ls");
    }
    else
    {
        int ret2 = fork();
        if (ret2 == 0)
        {
            // child 2
            close(fd[1]);
            dup2(fd[0], 0);
            system("sort");
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
}