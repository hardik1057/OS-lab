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
    char buffer1[] = "Hello from Parent to Child 4";
    char readbuffer1[30] = {};
    pipe(fd1);
    int r1 = fork();
    if (r1 == 0)
    {
        close(fd1[1]);
        read(fd1[0], readbuffer1, sizeof(readbuffer1));
        int fd2[2];
        pipe(fd2);
        int r2 = fork();
        if (r2 == 0)
        {
            close(fd2[1]);
            read(fd2[0], readbuffer1, sizeof(readbuffer1));
            int fd3[2];
            pipe(fd3);
            int r3 = fork();
            if (r3 == 0)
            {
                close(fd3[1]);
                read(fd3[0], readbuffer1, sizeof(readbuffer1));
                int fd4[2];
                pipe(fd4);
                int r4 = fork();
                if (r4 == 0)
                {
                    close(fd4[1]);
                    read(fd4[0], readbuffer1, sizeof(readbuffer1));
                    printf("%s", readbuffer1);
                }
                else if (r4 > 0)
                {
                    close(fd4[0]);
                    write(fd4[1], buffer1, strlen(buffer1));
                }
            }
            else if (r3 > 0)
            {
                close(fd3[0]);
                write(fd3[1], buffer1, strlen(buffer1));
            }
        }
        else if (r2 > 0)
        {
            close(fd2[0]);
            write(fd2[1], buffer1, strlen(buffer1));
        }
    }
    else if (r1 > 0)
    {
        close(fd1[0]);
        write(fd1[1], buffer1, strlen(buffer1));
    }
    return 0;
}
