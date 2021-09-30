// Program to implement close system call
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
    char buffer[51];
    int fd = open("test1.txt", O_RDONLY); //Opens the file with read only permission
    printf("File Descriptor = %d\n", fd);
    if (fd != -1) //Opening was successful
    {
        printf("test1.txt has been opened with read permission\n");
        read(fd, buffer, sizeof(buffer));
        buffer[50] = '\0';
        printf("----------------------------------------\n");
        printf("The first 50 characters in the file are:\n%s\n", buffer);
        close(fd); //Closes the file
        printf("----------------------------------------\n");
        printf("test1.txt has been closed\n");
    }
}