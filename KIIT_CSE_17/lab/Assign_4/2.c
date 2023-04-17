#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void create_process_tree(int level, int index)
{
    static int j = 0;
    int i = 0;
    if (j == level)
    {
        return;
    }
    int num;
    printf("\nEnter number of child for at level-%d and Index-%d:", j, index);
    scanf("%d", &num);
    printf("\nLevel-  %d, Index-  %d, Child-  %d\n", j, index, num);
    for (i = 0; i < num; i++)
    {
        if (fork() == 0)
        {
            j++;
            create_process_tree(level, i);
            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }
}

int main()
{
    int height, num;
    printf("Enter height of tree- ");
    scanf("%d", &height);
    create_process_tree(height, 0);
    return 0;
}
