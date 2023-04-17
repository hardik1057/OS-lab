#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd;
    char buffer[20];
    fd = open("myfifo", O_RDWR);
    while (1)
    {
        printf("User1: ");
        fgets(buffer, 20, stdin);
        write(fd, buffer, strlen(buffer) + 1);
        if (strcmp(buffer, "bye\n") == 0)
        {
            printf("You have disconnected\n");
            break;
        }
        sleep(4);
        read(fd, buffer, 20);
        if (strcmp(buffer, "bye") == 0)
        {
            printf("User2 has disconnected\n");
            break;
        }
        printf("User2: %s\n", buffer);
    }
    close(fd);
    remove( "myfifo");
    return 0;
}