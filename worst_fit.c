/* Program to implement the Worst fit algorithm on a 
            Fixed partition memory system            */
#include <stdio.h>
#include <stdlib.h>

typedef struct //To represent the free blocks of memory
{
    int bsize;
    int bflag;
    int bno;
} free_blocks;

free_blocks blocks[10];

typedef struct //To represent the processes
{
    int psize;
    int pflag;
    int pno;
    int balloted;
} process;

process processes[10];

void input(int m, int n) //To input the available free spaces and the processes
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        printf("Enter the amount of free space of Block %d: ", (i + 1));
        scanf("%d", &blocks[i].bsize);
        blocks[i].bflag = 0;
        blocks[i].bno = i + 1;
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the amount of memory required for Process %d: ", (i + 1));
        scanf("%d", &processes[i].psize);
        processes[i].pflag = 0;
        processes[i].pno = i + 1;
    }
}

void sort(int m) //To sort the free blocks in the descending order of their size
{
    free_blocks temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m - 1 - i; j++)
        {
            if (blocks[j].bsize < blocks[j + 1].bsize)
            {
                temp = blocks[j];
                blocks[j] = blocks[j + 1];
                blocks[j + 1] = temp;
            }
        }
    }
}

void worstFit(int m, int n) //To allocate the processes using worst fit scheme
{
    for (int i = 0; i < n; i++) //Taking each process
    {
        for (int j = 0; j < m; j++) //Taking each block
        {
            if ((blocks[j].bsize >= processes[i].psize) && (blocks[j].bflag == 0))
            {
                processes[i].balloted = blocks[j].bno;
                blocks[j].bflag = 1;
                processes[i].pflag = 1;
                break;
            }
        }
    }
}

void display(int m, int n) //To print the allocation calculated
{
    printf("\nProcess No.\tProcess size\tBlock No.\n");
    for (int i = 0; i < n; i++)
    {
        if (processes[i].pflag == 1)
        {
            printf("%d\t\t%d\t\t%d\n", processes[i].pno, processes[i].psize, processes[i].balloted);
        }
        else
        {
            printf("%d\t\t%d\t\tNot Alloted\n", processes[i].pno, processes[i].psize);
        }
    }
}

int main()
{
    int m, n;
    printf("Enter the number of free blocks of memory: ");
    scanf("%d", &m);
    if (m > 10)
    {
        printf("Maximum number of free blocks cannot exceed 10. Terminating...\n");
        exit(0);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    if (n > 10)
    {
        printf("Maximum number of processes cannot exceed 10. Terminating...\n");
        exit(0);
    }

    if (n > m)
    {
        printf("Number of processes cannot exceed number of free blocks. Terminating...\n");
        exit(0);
    }

    input(m, n);
    sort(m);
    worstFit(m, n);
    display(m, n);
    return 0;
}