// Round robnscheduling algorithm
#include<stdio.h>
struct process{
    int id, at, bt, wt,tt;
};

struct process a[10];

// declaration of ready queue
int queue[100];
int front=-1;
int rear=-1;

// function to insert element in into queue 
void insert(int n)
{
    if(front==-1)
        front=0;
    rear = rear + 1;
    queue[rear] = n;
}

// function to delete eleentfrom  queue
int delete()
{
    int n;
    n=queue[front];
    front=front+1;
    return n;
}
int main(){
    int n, tq, p, time = 0;
    int i;
    int temp[10], exist[10]={0};
    float total_wt=0, total_tt=0, avg_wt, avg_tt;
    printf("enter number of process: \n");
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        printf("Enter arrival time and burst time for process p%d respectively: \n", i+1);
        scanf("%d %d", &a[i].at, &a[i].bt);
        // copy the burst timein atemp array for further use of calculating waiting time later.
        temp[i] = a[i].bt;
    }
    printf("enter the time quantum: \n");
    scanf("%d", &tq);
    // logic for round robin sceheduling
    // insert first element inready queue
    insert(0);
    exist[0]=1;
    // until ready queue is empty
    while(front<=rear){
        p = delete();
        if(a[p].bt>=tq)
        {
            a[p].bt=a[p].bt-tq;
            time=time+tq;
        }
        else{
            time=time+a[p].bt;
            a[p].bt=0;
        }
        // if process not exist in ready queue 
        for(int i = 0; i<n; i++)
        {
            if(exist[i]==0 && a[i].at<=time){
                insert(i);
                exist[i]=1;
            }
        }
        //if process is completed
        if(a[p].bt==0)
        {
            a[p].tt=time-a[p].at;
            a[p].wt=a[p].tt-temp[p];
            total_tt=total_tt+a[p].tt;
            total_wt=total_wt+a[p].wt;
        }
        else
        {
            insert(p);
        }
    }
    
    avg_tt=total_tt/n;
    avg_wt=total_wt/n;
    
    // printing of the answer
    printf("ID WT TT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d  %d  %d\n",a[i].id,a[i].wt,a[i].tt);
    }
    printf("Average waiting time of the processes is : %f\n",avg_wt);
    printf("Average turn around time of the processes is : %f\n",avg_tt);
    return 0;
}
 