#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int i, ret, cnt = 0;
    for (i = 0; i < 2; i++)
    {
        ret = fork();
        cnt++;
        if (ret == 0 && cnt == 1)
        {
            printf("pid=%d ppid=%d\n", getpid(), getppid());
            break;
        }
        else if (ret == 0 && cnt == 2)
        {
            sleep(7);
            printf("pid=%d ppid=%d", getpid(), getppid());
        }
        else
        {
            sleep(3);
            printf("Parent process with pid= %d\n", getpid());
        }
    }
}
