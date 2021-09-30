/* Program to imlement the client side of a shared memory system 
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
    key_t key; //To store the key of the shared memory

    key = 9876;
    printf("Attempting to connect a shared memory region...\n");
    shmid = shmget(key, SH_SIZE, 0666); //Creating a shared memory
    if (shmid < 0)
    {
        perror("Error while connecting to shared memory. Terminating...\n");
        exit(1);
    }

    printf("Attempting to attatch the shared memory to client process...\n");
    shm = shmat(shmid, NULL, 0);

    if (shm == (char *)-1)
    {
        perror("Error in attatching shared memory to client process. Terminating...\n");
        exit(1);
    }
    printf("Reading the data from the shared memory region...\n\n");
    for (s = shm; *s != 0; s++)
    {
        printf("%c", *s);
    }

    printf("\n\nReading by client complete. Exiting client...\n");

    *shm = '*'; //To indicate that reading has been completed

    return 0;
}
