//Program to implement Round Robin scheduling algorithm in C
#include <stdio.h>
#include <limits.h>

struct PCB
{
    int pid, at, bt, st, ct, tat, wt, rt;
    //process id, arrival time, burst time, completion time, turn around time, waiting time and remaining time
};

int main()
{
    int n, j, qt;
    struct PCB p[10], temp;
    float awt = 0, atat = 0;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter the time quanta : ");
    scanf("%d", &qt);
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for Process %d : ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].pid = i + 1;
    }

    //Sort the processes according to their arrival times
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

    int cut = 0; //Current time
    int prev = 0;
    int compt = n; //Number of processes to be completed
    int i = 0, flag = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    while (compt != 0)
    {
        if (p[i].rt <= qt && p[i].rt > 0) // If the process has a remaining time lesser tham one time quanta
        {
            cut = cut + p[i].rt;
            p[i].rt = 0;
            flag = 1;
        }
        else if (p[i].rt > 0) // If the process has a remaining time greater than or equal one time quanta
        {
            cut = cut + qt;
            p[i].rt = p[i].rt - qt;
        }
        if (p[i].rt == 0 && flag == 1) // Code to be run when a process is complete
        {
            compt--;
            p[i].ct = cut;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            awt = awt + p[i].wt;
            atat = atat + p[i].tat;
            flag = 0;
            printf("\n%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        }

        // Code to increment to next process
        if (i == n - 1)
        {
            i = 0;
        }
        else if (p[i + 1].at <= cut)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    awt = awt / n;
    atat = atat / n;
    printf("\nThe Average Waiting Time is: %f", awt);
    printf("\nThe Average Turn Around Time is: %f\n", atat);
}