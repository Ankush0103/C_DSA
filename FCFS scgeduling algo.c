// FCFS scheduling algorithm
#include<stdio.h>
int main(){
    int at[10], bt[10], wt[10], tt[10], ct, i, n;
    int burst = 0;
    float avg_wt, avg_tt, total = 0;
    printf("enter number of process: \n");
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        printf("Enter arrival time and burst time for process p%d respectively: \n", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    // calcuclating waiting time
    for(int i = 0; i<n; i++){

        if(i==0)
            wt[i] = at[i];
        else
            wt[i] = burst - at[i];
        burst += bt[i];
        total += wt[i];
        printf("Waiting Time for process p%d is: %d\n", i+1, wt[i]);
    }
    avg_wt = total/n;
    // calculating turnaround time
    ct = 0;
    total = 0;
    for(int i =0; i<n; i++){
        ct += bt[i];
        tt[i] = ct - at[i];
        total += tt[i]; 
        printf("Turnaround Time for process p%d is: %d\n", i+1, tt[i]);
    }
    avg_tt = total/n;
    printf("Average waiting time and turnaround time for process are: %f and %f respectively\n", avg_wt, avg_tt);
    return 0;
}