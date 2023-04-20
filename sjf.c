#include<stdio.h>
void sort(int);
void burst_sort();
void inserter();
struct process
{
char p_name[20];
int p_at;
int p_bt;
int p_ct;
int p_wt;
int p_tat;
int p_flag;
}p[100],temp,q[100];
int front=-1,rear,completion_time=0,k=1;
void main()
{
	int n,i,temp_sum=0;
	float avg_wt,avg_tat;
	printf("Enter the number of process :- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		 printf("Enter the process name:\n");
		 scanf("%s",p[i].p_name);
   		 printf("Enter the process arrival time :- \n");
   	 	 scanf("%d",&p[i].p_at);
    		 printf("Enter the process burst time :-\n");
    		 scanf("%d",&p[i].p_bt);
		 p[i].p_flag=0;
	}
	sort(n);
	rear=n-1;
	front++;
	completion_time=completion_time+p[0].p_bt;
	p[0].p_ct = completion_time;
	q[0]=p[front];
	front++;
	burst_sort();
	inserter();
	for(i=0;i<n;i++)
	{
		q[i].p_tat = q[i].p_ct-q[i].p_at;
		q[i].p_wt = q[i].p_tat - q[i].p_bt;
	}
	printf("GANTT CHART\n");
int j;
	// print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<q[i].p_bt; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
 
    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<q[i].p_bt - 1; j++) printf(" ");
        printf("%s", q[i].p_name);
        for(j=0; j<q[i].p_bt - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<q[i].p_bt; j++) printf("--");
        printf(" ");
    }
    printf("\n");
 
    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<q[i].p_bt; j++) printf("  ");
        if(q[i].p_tat > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", q[i].p_ct);
 
    }
    printf("\n\n");
	printf("Process Name\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
	printf("------------------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",q[i].p_name,q[i].p_at,q[i].p_bt,q[i].p_ct,q[i].p_tat,q[i].p_wt);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		temp_sum = temp_sum + q[i].p_tat;
	}
	avg_tat = (float)temp_sum/n;
	printf("Average Turn around time is: %.2f",avg_tat);
	temp_sum = 0;
	printf("\n");
	for(i=0;i<n;i++)
	{
		temp_sum = temp_sum + q[i].p_wt;
	}
	avg_wt = (float)temp_sum/n;
	printf("Average waiting time is: %.2f",avg_wt);	
}
void sort(int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
    		for(j=0;j<n-i-1;j++)
    		{
        		if(p[j].p_at>p[j+1].p_at)
        		{
            			temp = p[j];
            			p[j]=p[j+1];
           		        p[j+1]=temp;
        		}
    		}
	}
}
void burst_sort()
{
	int i,j;
	for(i=front;i<=rear;i++)
	{
		for(j=front;j<=rear-i;j++)
		{
			if(p[j].p_bt>p[j+1].p_bt)
        		 {
            			temp = p[j];
            			p[j]=p[j+1];
           			p[j+1]=temp;
			 }
		}
	}
}
void inserter()
{
	int i;
	do
	{
		for(i=front;i<=rear;i++)
		{
			if(p[i].p_at<=completion_time && p[i].p_flag != 1)
			{
				p[i].p_flag=1;
				completion_time = completion_time+p[i].p_bt;
				p[i].p_ct = completion_time;
				q[k] = p[i];
				k++;
			}
		}
	}while(k<=rear);
}
	
