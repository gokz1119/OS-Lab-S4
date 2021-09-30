// Program to implement Banker's algorithm for deadlock avoidance

#include <stdio.h>
#include <stdlib.h>

int m, n; //To store the no. of resources and no. of processes
int allocation[10][10], max[10][10], need[10][10], available[10], flag[10], safe[10];

void input() //To input m, n, allocation matrix and max matrix
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    if (n > 10)
    {
        printf("Number of processes cannot exceed 10. Terminating...\n");
        exit(0);
    }
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    if (m > 10)
    {
        printf("Number of resources cannot exceed 10. Terminating...\n");
        exit(0);
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the resource allocation of Process %d: ", (i + 1));
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the maximum resource requirement of Process %d: ", (i + 1));
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the availability of the resources: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    for (int i = 0; i < n; i++)
        flag[i] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void banker() //To implement the banker's algorithm
{
    int x = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (flag[i] == 0)
            {
                int f = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        f = 1;
                        break;
                    }
                }

                if (f == 0) //Need is less than the availability
                {
                    for (int j = 0; j < m; j++)
                        available[j] = available[j] + allocation[i][j];
                    safe[x] = i;
                    x++;
                    flag[i] = 1;
                }
            }
        }
    }
}

void display() //To display the safe sequence
{
    int i;
    printf("\nThe safe sequence is: ");
    for (i = 0; i < (n - 1); i++)
    {
        printf(" P%d -> ", safe[i]);
    }
    printf(" P%d\n", safe[i]);
}

int main()
{
    input();
    banker();
    display();

    return 0;
}