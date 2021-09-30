/* Program to implement Counting Semaphores in C */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int shared = 100; //This is the variable that is accesed by both processes

typedef struct
{
    int value;
    pthread_mutex_t lock;
    pthread_cond_t wait;
} semaphore;

void init_sem(semaphore *s, int n)
{
    s->value = n;
    pthread_cond_init(&(s->wait), NULL);
    pthread_mutex_init(&(s->lock), NULL);
    return;
}

void wait_sem(semaphore *s)
{
    pthread_mutex_lock(&(s->lock));
    s->value--;
    if (s < 0)
    {
        pthread_cond_wait(&(s->wait), &(s->lock));
    }
    pthread_mutex_unlock(&(s->lock));
    return;
}

void signal_sem(semaphore *s)
{
    pthread_mutex_lock(&(s->lock));
    s->value++;
    if (s->value <= 0)
    {
        pthread_cond_signal(&(s->wait));
    }
    pthread_mutex_unlock(&(s->lock));
}

void *increment(semaphore *s, int pro_num) //This funtion will increment the value of the shared variable
{
    printf("Process %d has started execution\n", pro_num);
    wait_sem(s);
    //Starting critical section
    printf("------------------------------------------------\n");
    printf("Process %d has entered the Critical Section\n", pro_num);
    int a = shared; //Getting a local copy of shared variable
    printf("Value of the shared variable received by Process %d: %d\n", pro_num, a);
    a++;
    shared = a; //Updating the shared variable
    printf("The value of shared variable after updation from Process %d: %d\n", pro_num, shared);
    printf("The Process %d is leaving the critical section\n", pro_num);
    printf("------------------------------------------------\n");
    signal_sem(s);
    printf("End of Process %d\n", pro_num);
}

void *decrement(semaphore *s, int pro_num) //This function will decrement the value of the shared variable
{
    printf("The Process %d has started execution\n", pro_num);
    wait_sem(s);
    //Starting critical section
    printf("------------------------------------------------\n");
    printf("The Process %d has entered the Critical Section\n", pro_num);
    int a = shared; //Getting a local copy of shared variable
    printf("Value of the shared variable received by Process %d: %d\n", pro_num, a);
    a--;
    shared = a; //Updating the shared variable
    printf("The value of shared variable after updation from Process %d: %d\n", pro_num, shared);
    printf("The Process %d is leaving the critical section\n", pro_num);
    printf("------------------------------------------------\n");
    signal_sem(s);
    printf("End of Process %d\n", pro_num);
}

int main()
{
    int initial_shared = shared; //Creating a copy of the shared variable before any operation
    printf("The initial value of the shared variable: %d\n", initial_shared);

    semaphore *sem;
    init_sem(sem, 4);

    pthread_t process1, process2, process3, process4; //The threads represent the two processes sharing the variable
    pthread_create(&process1, NULL, increment(sem, 1), NULL);
    pthread_create(&process2, NULL, decrement(sem, 2), NULL);
    pthread_create(&process3, NULL, increment(sem, 3), NULL);
    pthread_create(&process4, NULL, decrement(sem, 4), NULL);

    pthread_join(process1, NULL);
    pthread_join(process2, NULL);
    pthread_join(process3, NULL);
    pthread_join(process4, NULL);

    return 0;
}