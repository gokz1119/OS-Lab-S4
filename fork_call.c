// Program to implement fork system call
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
    int x = fork();
    printf("Hello World!\nx = %d\n", x);
    if (x == 0)
        printf("Hello from the child process!\n");
    else
        printf("Hello form the parent process!\n");
}