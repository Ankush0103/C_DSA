// SRTF 2
#include <stdio.h>
int main()
{
    int at[10], bt[10], rt[10], endTime, i, smallest;
    int remain = 0, n, time, avg_wait = 0, avg_turnaround = 0;
    printf("enter number of process: \n");
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        printf("Enter arrival time and burst time for process p%d respectively: \n", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("\n\nProcess\t Waiting Time\t Turnaround Time\n\n");
    //rt[9] = 9999;
    for (time = 0; remain != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
            {
                smallest = i;
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0)
        {
            remain++;
            endTime = time + 1;
            printf("\nP%d\t\t%d\t\t%d", smallest + 1, endTime - bt[smallest] - at[smallest], endTime - at[smallest]);
            avg_wait += endTime - bt[smallest] - at[smallest];
            avg_turnaround += endTime - at[smallest];
        }
    }
    printf("\n\nAverage waiting time = %f\n", avg_wait * 1.0 / n);
    printf("Average Turnaround time = %f", avg_turnaround* 1.0 / n);
    return 0;
}