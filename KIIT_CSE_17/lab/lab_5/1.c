#include<stdio.h>
#include<unistd.h>
#include <string.h>
int main()
{
    int fd1[2], fd2[2];
    char writing1[20];
    strcpy(writing1, "Hello");
    char writing2[20];
    strcpy(writing2, "Hi!");
    char reading[20];
    char reading1[20];
    pipe(fd1);
    pipe(fd2);
    int pid = fork();
    if(pid!=0)
    {
        close(fd1[0]);
        close(fd2[1]);
        printf("In parent- writing to pipe 1- %s\n", writing1);
        int ret=write(fd1[1],writing1,(strlen(writing1)));
        //printf("return value of write=%d\n", ret);
        read(fd2[0], reading1, (sizeof(reading1)));
        printf("In parent- reading from pipe 2- %s\n", reading1);
    }
    else
    {
        close(fd1[1]);
        close(fd2[0]);
        int ret=read(fd1[0], reading, (sizeof(reading)));
        //printf("return value of read=%d\n", ret);
        printf("In child- reading from pipe 1- %s\n", reading);
        printf("In child- writing to pipe 2- %s\n", writing2);
        write(fd2[1],writing2,(strlen(writing2)+1));
    }
    return 0;
}
