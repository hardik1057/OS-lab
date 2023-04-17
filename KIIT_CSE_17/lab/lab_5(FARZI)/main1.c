#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main() 
{
    for (int i = 0; i < 3; i++) 
    {
        int ret = fork();
        if (ret == 0) 
        {  
            printf("Process %d, parent %d\n", getpid(), getppid());
            if (i == 1) 
            {  
                int j;
                for (j = 0; j < 1; j++) 
                {
                    int ret2 = fork();
                    if (ret2 == 0) 
                    {  
                        printf("Child process %d, parent %d\n", getpid(), getppid());
                        for (int k = 0; k < 2; k++)
                        {
                            int ret3 = fork();
                            if (ret3 == 0) 
                            {  
                                printf("Grandchild process %d, parent %d\n", getpid(), getppid());
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
            break;
        }
        else 
        {  
            printf("Parent process %d\n", getpid());
            wait(NULL);
        }
    }
    return 0;
}

