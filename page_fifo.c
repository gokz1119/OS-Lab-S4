// Program to implement Page Replacement FIFO algorithm

#include <stdio.h>
#include <stdlib.h>

int num_pages, frames, page_faults, hits, referenceString[20], pages[20];
int front = -1;
int rear = -1;

int pagesfull() //Functio to check Circular Queue full
{
    if ((front == rear + 1) || (front == 0 && rear == frames - 1))
        return 1;
    else
        return 0;
}

void pagesinsert(int data) //Function for Insert operation
{
    if (front == -1)
        front = 0;
    rear = (rear + 1) % frames;
    pages[rear] = data;
}

void pagesdelete() //Function to delete elements
{
    int elem = pages[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % frames;
}

void input() //To input the no. of frames, no. of pages and the reference string
{
    printf("Enter the number of pages in reference string: ");
    scanf("%d", &num_pages);
    if (num_pages > 20)
    {
        printf("Number of pages cannot exceed 20. Terminating...\n");
        exit(0);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    if (frames > 20)
    {
        printf("Number of frames cannot exceed 20. Terminating...\n");
        exit(0);
    }

    printf("Enter the reference string separated by spaces: ");
    for (int i = 0; i < num_pages; i++)
    {
        scanf("%d", &referenceString[i]);
    }
    for (int i = 0; i < frames; i++)
    {
        pages[i] = -1;
    }
}

void display(int i, int hit_miss) //To print the page table after each iteration
{
    printf("%d.\t\t", i);
    for (int j = 0; j < frames; j++)
    {
        if (pages[j] != -1)
            printf("%d\t\t", pages[j]);
        else
            printf("-\t\t");
    }
    if (hit_miss == 1)
        printf("Hit\n");
    else
        printf("Miss\n");
}

void fifo() //To implement the algorithm
{
    int flag, hit_miss;
    for (int i = 0; i < num_pages; i++)
    {
        hit_miss = 0;
        flag = 0;
        for (int j = 0; j < frames; j++)
        {
            if (pages[j] == referenceString[i])
            {
                hits++;
                hit_miss = 1;
                flag = 1;
                break;
            }
        }
        if ((flag == 0) && (!pagesfull()))
        {
            page_faults++;
            pagesinsert(referenceString[i]);
            flag = 1;
        }
        else if ((flag == 0) && (pagesfull()))
        {
            page_faults++;
            pagesdelete();
            pagesinsert(referenceString[i]);
            flag = 1;
        }
        if (i == 0)
        {
            printf("\nSl. No\t\t");
            for (int k = 0; k < frames; k++)
                printf("Frame %d\t\t", (k + 1));
            printf("Hit/Miss\n");
        }
        display((i + 1), hit_miss);
    }
}

int main()
{
    input();
    fifo();

    printf("\nPage Faults = %d\n", page_faults);
    float hit_ratio = (float)hits / num_pages;
    printf("Hit Ratio = %f\n", hit_ratio);
}