//Program to implement FCFS algorithm in C
#include <stdio.h>

struct PCB
{
    int pid, at, bt, ct, wt, tat;
    //process id, arrival time, burst time, completion time, waiting time and turn around time
};
struct PCB p[10];

void insert(int n) //To input the arrival times and the burst times
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time of process %d: ", (i + 1));
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
    }
}

void sort(int n) //To sort the processes based on the arrival times
{
    struct PCB temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void calculate_ct(int n) //To calculate the completion times
{
    p[0].ct = p[0].at + p[0].bt;
    for (int i = 1; i < n; i++)
    {
        p[i].ct = p[i - 1].ct + p[i].bt;
    }
}

void calculate_tat_and_wt(int n) //To calculate turn around time
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

int main()
{
    int i, n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    insert(n);
    sort(n);
    calculate_ct(n);
    calculate_tat_and_wt(n);

    int tot_tat, tot_wt;
    float avg_tat, avg_wt;
    tot_tat = 0;
    tot_wt = 0;
    for (i = 0; i < n; i++)
    {
        tot_tat = tot_tat + p[i].tat;
        tot_wt = tot_wt + p[i].wt;
    }
    avg_tat = (float)tot_tat / n;
    avg_wt = (float)tot_wt / n;

    printf("PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage turn around time: %f\n", avg_tat);
    printf("Average waiting time: %f\n", avg_wt);

    return 0;
}