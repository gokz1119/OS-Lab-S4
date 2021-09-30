// Program to implement the getpid system call
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
    pid_t pid;
    pid_t parent_pid;
    int x = fork();
    if (x == 0)
    {
        printf("New child process created with PID = %d\n", getpid());
        printf("PID of parent of newly created process = %d\n", getppid());
    }
    else
    {
        pid = getpid();
        parent_pid = getppid();
        printf("PID of current process = %d\n", pid);
        printf("PID of parent process = %d\n", parent_pid);
    }
}