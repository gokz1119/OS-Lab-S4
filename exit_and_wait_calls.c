// Program to implement exit and wait system calls
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
    pid_t x = fork();
    if (x == 0) //Child process
    {
        printf("This is the child process\n");
        printf("PID of child process = %d\n", getpid());
        printf("Exiting child process\n");
        exit(0);                               //Child process gets terminated here
        printf("Exited from child process\n"); //This statement will not be executed
    }
    else //Parent process
    {
        printf("This is the parent process\n");
        printf("Waiting for the child process to finish\n");
        wait(NULL); //Execution of parent is halted
        printf("Child process terminated; Returned to parent process\n");
    }
    printf("Done\n");
}