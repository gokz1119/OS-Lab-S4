// Program to implement Page Replacement LFU algorithm

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pageno;
    int freq;
} page;

page pages[20];
int num_pages, frames, page_faults, hits, referenceString[20];

int isnotfull() //To check whether the frames are full or not
{
    int count = 0;
    for (int i = 0; i < frames; i++)
    {
        if (pages[i].pageno != -1)
            count++;
    }
    if (count < frames)
        return count;
    else
        return -1;
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
        pages[i].pageno = -1;
        pages[i].freq = 0;
    }
}

void display(int i, int hit_miss) //To print the page table after each iteration
{
    printf("%d.\t\t", i);
    for (int j = 0; j < frames; j++)
    {
        if (pages[j].pageno != -1)
            printf("%d\t\t", pages[j].pageno);
        else
            printf("-\t\t");
    }
    if (hit_miss == 1)
        printf("Hit\n");
    else
        printf("Miss\n");
}

void pageLFU() //To implement the algorithm
{
    int flag, hit_miss;
    for (int i = 0; i < num_pages; i++)
    {
        hit_miss = 0;
        flag = 0;
        for (int j = 0; j < frames; j++)
        {
            if (pages[j].pageno == referenceString[i])
            {
                hits++;
                pages[j].freq++;
                hit_miss = 1;
                flag = 1;
                break;
            }
        }

        int count = isnotfull();
        if ((flag == 0) && (count != -1))
        {
            page_faults++;
            pages[count].pageno = referenceString[i];
            pages[count].freq++;
            flag = 1;
        }
        else if ((flag == 0) && (count == -1))
        {
            int lfu = pages[0].freq; //Index of  Least Frequently used page
            int lpage = 0;           //Least Frequently used page
            for (int k = 1; k < frames; k++)
            {
                if (pages[k].freq < lfu)
                {
                    lfu = pages[k].freq;
                    lpage = k;
                }
            }

            page_faults++;
            pages[lpage].pageno = referenceString[i];
            pages[lpage].freq++;
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
    pageLFU();

    printf("\nPage Faults = %d\n", page_faults);
    float hit_ratio = (float)hits / num_pages;
    printf("Hit Ratio = %f\n", hit_ratio);
}