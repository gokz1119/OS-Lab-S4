/* Program to implement Semaphores in C */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int s = 1;        //This is the semaphore variable
int shared = 100; //This is the variable that is accesed by both processes
void wait_sem()
{
    while (s <= 0)
        ; //Waiting for other process to finish
    s--;
}

void signal_sem()
{
    s++;
}

void *increment() //This funtion will increment the value of the shared variable
{
    printf("Process 1 has started execution\n");
    wait_sem();
    //Starting critical section
    printf("------------------------------------------------\n");
    printf("Process 1 has entered the Critical Section\n");
    int a = shared; //Getting a local copy of shared variable
    printf("Value of the shared variable received by Process 1: %d\n", a);
    printf("Process 1 going to sleep\n");
    sleep(3);
    a++;
    shared = a; //Updating the shared variable
    printf("The value of shared variable after updation from Process 1: %d\n", shared);
    printf("The Process 1 is leaving the critical section\n");
    printf("------------------------------------------------\n");
    signal_sem();
    printf("End of Process 1\n");
}

void *decrement() //This function will decrement the value of the shared variable
{
    printf("The Process 2 has started execution\n");
    wait_sem();
    //Starting critical section
    printf("------------------------------------------------\n");
    printf("The Process 2 has entered the Critical Section\n");
    int a = shared; //Getting a local copy of shared variable
    printf("Value of the shared variable received by Process 2: %d\n", a);
    printf("Process 2 going to sleep\n");
    sleep(3);
    a--;
    shared = a; //Updating the shared variable
    printf("The value of shared variable after updation from Process 2: %d\n", shared);
    printf("The Process 2 is leaving the critical section\n");
    printf("------------------------------------------------\n");
    signal_sem();
    printf("End of Process 2\n");
}

int main()
{
    int initial_shared = shared; //Creating a copy of the shared variable before any operation
    printf("The initial value of the shared variable: %d\n", initial_shared);

    pthread_t process1, process2; //The threads represent the two processes sharing the variable
    pthread_create(&process1, NULL, increment, NULL);
    pthread_create(&process2, NULL, decrement, NULL);

    pthread_join(process1, NULL);
    pthread_join(process2, NULL);

    if (initial_shared == shared)
        printf("Since the initial and final values of the shared variable are the same, Semaphore implementation is successful!\n");

    else
        printf("Since the initial and final values of the shared variable are not the same, Semaphore implementation is unsuccessful!\n");

    return 0;
}