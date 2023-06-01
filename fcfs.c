#include<stdio.h>
struct process
{
int arrival_time;
int burst_time;
int completion_time;
int waiting_time;
int turn_Around_time;
}p[100],temp;
int main()
{
int i,n,k=0,temp_sum=0,j,l;
float avg_time,avg_time1;
printf("Enter the no. of processes = ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("Enter the process %d arrival time = ",i+1);
    scanf("%d",&p[i].arrival_time);
    printf("Enter the process %d burst time = ",i+1);
    scanf("%d",&p[i].burst_time);
}
for(i=0;i<n-1;i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if(p[j].arrival_time>p[j+1].arrival_time)
        {
            temp = p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
        }
    }
}
for(i=0;i<n;i++)
{
    for(l=0;l<=k;l++)
    {
        temp_sum=temp_sum+p[l].burst_time;
    }
    p[i].completion_time=temp_sum;
    temp_sum=0;
    if(k<n)
    k++;
}
for(i=0;i<n;i++)
{
p[i].turn_Around_time=p[i].completion_time-p[i].arrival_time;
p[i].waiting_time=p[i].turn_Around_time-p[i].burst_time;
}
printf("Process Number\tArrival Time\tBurst Time\tCompletion Time\tTurnAround Time\tWaiting Time\n");
for(i=0;i<n;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].arrival_time,p[i].burst_time,p[i].completion_time,p[i].turn_Around_time,p[i].waiting_time);
}


temp_sum=0;
printf("Average waiting time is :- ");
for(i=0;i<n;i++)
{
    temp_sum=temp_sum+p[i].waiting_time;
}
avg_time=(float)temp_sum/n;
printf("%f\n",avg_time);
temp_sum=0;
printf("Average Turn Around time is = ");
for(i=0;i<n;i++)
{
    temp_sum=temp_sum+p[i].turn_Around_time;
}
avg_time1=(float)temp_sum/n;
printf("%f\n",avg_time1);

    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
 
    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("P%d", i+1);
        for(j=0; j<p[i].burst_time - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");
 
    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("  ");
        if(p[i].turn_Around_time > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", p[i].completion_time);
 
    }
printf("\n");
}