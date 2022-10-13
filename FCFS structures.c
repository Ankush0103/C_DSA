#include<stdio.h>
struct process
{
    int at,wt,tt,bt;
};

struct process a[10];
int main()
{
    int i, n;
    int burst=0,ct;
    float avg_wt, avg_tt, total = 0;
    printf("Enter number of process\n");
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        printf("Enter arrival time and burst time for process p%d respectively: \n", i+1);
        scanf("%d %d", &a[i].at, &a[i].bt);
    }
    
    // Logic for calculating Waiting time
    for(int i=0;i<n;i++)
    {
        if(i==0)
            a[i].wt=a[i].at;
        else
            a[i].wt=burst-a[i].at;
        burst+=a[i].bt;
        total+=a[i].wt;
        printf("Waiting Time for process p%d is: %d\n", i+1, a[i].wt);
    }
    avg_wt=total/n;
    
    // Logic for calculating Turn around  time
    ct=0;
    total=0;
    for(int i=0;i<n;i++)
    {
        ct += a[i].bt;
        a[i].tt = ct -a[i].at;
        total += a[i].tt;
        printf("Turnaround Time for process p%d is: %d\n", i+1, a[i].tt);
    }
    avg_tt= total/n;
    
    // printing of outputs
    
    
    printf("Average waiting time is : %f\n",avg_wt);
    printf("Average turn around time is : %f\n",avg_tt);
    return 0;
}