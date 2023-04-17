#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// implementing ls | sort
int main(int argc, char **argv)
{
    // Create a pipe in parent
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        printf("parent: failed to create pipe\n");
        return 1;
    }
    // We need to fork two processes, one for ls, and another one for sort
    int pid_ls = fork();
    if (pid_ls == -1)
    {
        printf("parent: could not fork process to run ls\n");
        return 1;
    }
    if (pid_ls == 0)
    { // Child
        printf("child: running ls\n");
        // Merge stdout of ls to write end of pipe.
        // if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
        if (dup2(pipefd[1], 1) == -1)
        {
            printf("child: failed to call dup2 for ls\n");
            return 1;
        }
        close(pipefd[0]);
        close(pipefd[1]);
        system("ls");
        return -1;
    }
    // Parent Continue forking
    int pid_sort = fork();
    if (pid_sort == -1)
    {
        printf("parent: could not fork process to run sort\n");
        return 1;
    }
    if (pid_sort == 0)
    { // Child
        printf("child: running sort\n");
        // Merge stdin of sort to read end of pipe.
        // if (dup2(pipefd[0], STDIN_FILENO) == -1) {
        if (dup2(pipefd[0], 0) == -1)
        {
            printf("child: failed to call dup2 for sort\n");
            return 1;
        }
        close(pipefd[0]);
        close(pipefd[1]);
        system("sort");
        return -1;
    }
    close(pipefd[0]);
    close(pipefd[1]);
    printf("parent: wait for children\n");
    while (wait(NULL) > 0);
    printf("parent: done!\n");
    return 0;
}
