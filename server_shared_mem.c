/* Program to imlement the server side of a shared memory system 
   for Interprocess Communication */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SH_SIZE 100 //Size of the shared memory in bytes

int main()
{
    int shmid; //To store the id of the shared memory
    char *shm; //To store the messege to be used in the shared memory
    char *s;
    char *msg = "Hello client. This is the message from the server";
    key_t key; //To store the key of the shared memory

    key = 9876;
    printf("Attempting to create a shared memory region...\n");
    shmid = shmget(key, SH_SIZE, IPC_CREAT | 0666); //Creating a shared memory
    if (shmid < 0)
    {
        perror("Error while creating a shared memory. Terminating...\n");
        exit(1);
    }

    printf("Shared memory region was created successfully...\n");
    system("ipcs -m");

    printf("Attempting to attatch the shared memory to server process...\n");
    shm = shmat(shmid, NULL, 0);

    if (shm == (char *)-1)
    {
        perror("Error in attatching shared memory to server process. Terminating...\n");
        exit(1);
    }

    printf("Writing data into the shared memory region...\n");
    strcpy(shm, msg);
    printf("Writing of data from server process complete...\n\n");
    s = shm;
    s += 49;
    *s = 0; //To identify the last character

    while (*shm != '*') //When *shm = '*', reading is complete by other process
    {
        printf("Waiting for client process to finish reading...\n");
        sleep(2);
    }

    printf("Reading has been completed by client process. Exiting server...\n");
    return 0;
}
