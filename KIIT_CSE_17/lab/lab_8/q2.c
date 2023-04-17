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
        dup2(fd[1],1);
        close(fd[0]);
        close(fd[1]);
        char *ls_args[] = {"ls", "-la", NULL};
        execve("/usr/bin/ls", ls_args, NULL);
    }
    else
    {
        int ret2 = fork();
        if (ret2 == 0)
        {
            // child 2
            dup2(fd[0], 0);
            close(fd[0]);
            close(fd[1]);
            char *sort_args[] = {"sort", NULL};
            execve("/usr/bin/sort", sort_args, NULL);
        }
        else
        {
            // parent
            close(fd[0]);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
        }
    }
    return 0;
}
