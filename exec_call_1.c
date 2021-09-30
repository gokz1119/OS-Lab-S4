// Program to implement exec system call
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
    printf("Hello World! This is exe1\n");
    printf("PID of exe1 = %d\n", getpid());
    printf("Calling exe2\n");
    char *args[] = {"Hello", NULL};
    execv("./exe2", args);
    printf("Returned to exe1\n");
}