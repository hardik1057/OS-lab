#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int fd_read, fd_write;
    char buffer[20];
    mkfifo("myfifo", 0666);
    fd_read = open("myfifo", O_RDONLY);
    fd_write = open("myfifo", O_WRONLY);
    while (1)
    {
        sleep(4);
        read(fd_read, buffer, 20);
        if (strcmp(buffer, "bye") == 0)
        {
            printf("User1 has disconnected\n");
            break;
        }
        printf("User1: %s\n", buffer);
        printf("User2: ");
        fgets(buffer, 20, stdin);
        write(fd_write, buffer, strlen(buffer) + 1);
        if (strcmp(buffer, "bye\n") == 0)
        {
            printf("You have disconnected\n");
            break;
        }
    }
    close(fd_read);
    close(fd_write);
    unlink("myfifo");
    return 0;
}