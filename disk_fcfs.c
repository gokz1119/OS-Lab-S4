// Program to implement FCFS Disk scheduling algorithm

#include <stdio.h>
#include <stdlib.h>

int n, head, seek_count, tracks[20];

void input() //To input the starting position and the tracks to be seeked
{
    printf("Enter the number of tracks to be seeked: ");
    scanf("%d", &n);
    if (n > 20)
    {
        printf("Number of tracks to be seeked cannot exceed 20. Terminating...\n");
        exit(0);
    }

    printf("Enter the starting position of the head: ");
    scanf("%d", &head);

    printf("Enter the tracks to be seeked: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }
}

void fcfs() //To implement the algorithm
{
    int cur_track, distance;
    seek_count = 0;

    for (int i = 0; i < n; i++)
    {
        cur_track = tracks[i];
        distance = abs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }
}

void display() //To display the sequence and the seek count
{
    printf("The Seek Sequence is: ");
    for (int i = 0; i < n - 1; i++)
        printf(" %d -> ", tracks[i]);
    printf(" %d\n", tracks[n - 1]);

    printf("The Seek Count is: %d\n", seek_count);
}

int main()
{
    input();
    fcfs();
    display();

    return (0);
}