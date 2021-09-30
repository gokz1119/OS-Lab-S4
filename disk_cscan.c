// Program to implement Cscan Disk Scheduling algorithm

#include <stdio.h>
#include <stdlib.h>

int n, head, size, seek_count, tracks[20], sequence[20];

void input() //To input the starting position and the tracks to be seeked
{
    printf("Enter the size of the disk: ");
    scanf("%d", &size);
    printf("Enter the number of tracks to be seeked: ");
    scanf("%d", &n);
    if (n > 20)
    {
        printf("Number of tracks to be seeked cannot exceed 20. Terminating...\n");
        exit(0);
    }

    printf("Enter the starting position of the head: ");
    scanf("%d", &head);
    if (head > size)
    {
        printf("Starting position of head cannot exceed the size of disk. Terminating...\n");
        exit(0);
    }

    printf("Enter the tracks to be seeked: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }
}

void sort(int arr[], int m)
{
    int temp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void scan() //To implement the scan algorithm
{
    int cur_track, distance, l, r, left[20], right[20];
    seek_count = 0;
    l = 0;
    r = 0;

    left[0] = 0;
    l++;
    right[0] = size - 1;
    r++;

    for (int i = 0; i < n; i++)
    {
        if (tracks[i] < head)
            left[l++] = tracks[i];
        if (tracks[i] > head)
            right[r++] = tracks[i];
    }

    sort(left, l);
    sort(right, r);

    int x = 0;

    for (int i = 0; i < r; i++)
    {
        cur_track = right[i];
        sequence[x++] = cur_track;
        distance = abs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }

    head = 0;
    seek_count += size - 1;

    for (int i = 0; i < l; i++)
    {
        cur_track = left[i];
        sequence[x++] = cur_track;
        distance = abs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }
}

void display() //To display the sequence
{
    int i;
    printf("The Seek Sequence is: ");
    for (i = 0; i < n + 1; i++)
        printf(" %d -> ", sequence[i]);
    printf(" %d\n", sequence[i]);

    printf("The Seek Count is: %d\n", seek_count);
}

int main()
{
    input();
    scan();
    display();

    return 0;
}