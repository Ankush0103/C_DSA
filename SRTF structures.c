#include<stdio.h>
struct process{
    int wt, at, bt, tt;
};
struct process a[10];
int main(){
    int i, n, temp[10];
    int count = 0, t=0, short_p;
    float total_wt = 0, total_tt = 0, avg_wt, avg_tt;
    printf("Enter number of process\n");
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        printf("Enter arrival time and burst time for process p%d respectively: \n", i+1);
        scanf("%d %d", &a[i].at, &a[i].bt);
        // copy the burst timein atemp array for further use of calculating waiting time later.
        temp[i] = a[i].bt;
    }
    // we initialize the burst time of process with maximum
    a[9].bt = 10000;
    // loop will be execute until all process complete so we use count!= number of process
    for(t = 0; count!=n; t++)
    {
        // to find minburst it is useful
        short_p = 9;
        for(int i = 0; i<n; i++)
        {
            if(a[i].bt<a[short_p].bt && (a[i].at<=t && a[i].bt>0))
            {
                short_p = i;
            }
        }
        a[short_p].bt = a[short_p].bt - 1;
        // if any process is completed
        if(a[short_p].bt==0)
        {
            // one process is complete
            count++;
            a[short_p].wt=t+1-a[short_p].at-temp[short_p];
            a[short_p].tt=t+1-a[short_p].at;
            
            // total calculation
            total_wt=total_wt+a[short_p].wt;
            total_tt=total_tt+a[short_p].tt;
        }
    }
    avg_wt = total_wt/n;
    avg_tt = total_tt/n;

    // printing of the answer
    printf("Id wt tat\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",i+1,a[i].wt,a[i].tt);
    }
    printf("Avg waiting time of the process is %f\n",avg_wt);
    printf("Avg turn around time of the process %f\n",avg_tt);

}
