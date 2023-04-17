#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int fd1[2];
    int fd2[2];
    char buffer1[] = "Hello from Child 1";
    char buffer2[] = "Hello from Child 2";
    char readbuffer1[30] = {};
    char readbuffer2[30] = {};
    pipe(fd1);
    int r = fork();
    if (r == 0)
    {
        close(fd1[1]);
        read(fd1[0], readbuffer1, sizeof(readbuffer1));
        printf("%s\n", readbuffer1);
    }
    else if (r > 0)
    {
        pipe(fd2);
        int c = fork();
        if (c == 0)
        {
            close(fd2[1]);
            read(fd2[0], readbuffer2, sizeof(readbuffer2));
            printf("%s\n", readbuffer2);
        }
        else
        {
            close(fd1[0]);
            close(fd2[0]);
            write(fd1[1], buffer1, strlen(buffer1));
            write(fd2[1], buffer2, strlen(buffer2));
        }
    }
    return 0;
}
