#include<stdio.h>
#include<stdlib.h>
int i,j,n,time=0,tempt=0,c,z=0,x=0,tar=0;

struct Process
{
 int pid;
 int wt;
 int bt;
 int at;
 int ct;
 int tat;
 int rt;
 int flag;
}p[10],temp[10],temp1[10],temp3[30];
 
int at[10],flag,tq;
float avgtat,avgwt;

void sort()
{
 for(i=0;i<n;i++)
 {
    for(j=0;j<n-i-1;j++)
    {
   	 if(p[j+1].at<p[j].at)
   	 {
   	 temp1[0]=p[j];
   	 p[j]=p[j+1];
   	 p[j+1]=temp1[0];
   	 }
    }
 }
}

void compute()
{
 int y=n;
 for(i=0;i<n;i++)
 {
 
 if(p[i].bt>tq)
 {
    p[i].rt=tq;    
    time+=tq;    
    tar=0;
    for(int j=i+1;j<n;j++)
    {
   	 if(p[j].at<=time)
   	 tar++;
    }   		 
 
    for(int j=n-1;j>i+tar;j--)
    {
   	 p[j+1]=p[j];
    }    
    p[i+tar+1]=p[i];   				 
    p[i+tar+1].bt=p[i+tar+1].bt-tq;   				 
    n++;
 }
 
 else
 {
  p[i].rt=p[i].bt;
  time+=p[i].rt;
  p[i].ct=time;
 }
 
 }
 
 z=0;
 for(int i=0;i<n;i++)
 {
    if(p[i].ct!=0)
    {
   	 temp[z]=p[i];
   	 flag=0;
   	 for(int j=0;j<i;j++)
   	 {
   		 if(p[i].pid==p[j].pid && flag==0)
   		 {
   		 temp[z].bt=p[j].bt;
   		 flag=1;
   		 }   	 
   	 }
   	 z++;
    }
 }
 
 for(i=0;i<z;i++)
 {
    temp[i].tat=temp[i].ct-temp[i].at;
    temp[i].wt=temp[i].tat-temp[i].bt;    
    avgwt+=temp[i].wt;
    avgtat+=temp[i].tat;
 }
 avgtat=avgtat/y;
 avgwt=avgwt/y;
}

void table()
{
 printf("\n");
 printf("*----------------------------------------------------------------------------------------------*\n");
 printf("|  Pid  |  Arrival Time  |  Burst Time  |  Turn Around Time  |  Waiting Time  |  Completion Time\n");
 printf("*----------------------------------------------------------------------------------------------*\n");
 for(i=0;i<z;i++)
 {
    printf("|  %2d  |  	%2d    	  |  	%2d  	 |      	%2d    	  |  	%2d    	   |  	%2d    	    |\n",temp[i].pid,temp[i].at,temp[i].bt,temp[i].tat,temp[i].wt,temp[i].ct);
 }
 printf("*----------------------------------------------------------------------------------------------*\n");
}

void ganttchart()
{
    //gant chart(Topline)
 printf("\n\n\t\tGantt Chart\n\n ");
 for(i=0;i<n;i++)
 {
    for(int j=0;j<p[i].rt;j++)
    printf("--");
  printf(" ");
 }    
 printf("\n ");
 for(i=0;i<n;i++)
 {
    for(int j=0;j<p[i].rt-1;j++)
    printf(" ");
 
    printf("P%d",p[i].pid);
 
    for(int j=0;j<p[i].rt-1;j++)
    printf(" ");
    printf("|");
 }    
 printf("\n ");
 
 //bottomline
 for(i=0;i<n;i++)
 {
    for(int j=0;j<p[i].rt;j++)
    printf("--");
  printf(" ");
 }    
 printf("\n");

//num
 printf("0");
 time=0;
 for(i=0;i<n;i++)
 {
    for(j=0;j<p[i].rt;j++)
    {    
    printf("  ");
    time++;
    }    
    printf("\b");
    if (time>10)
    printf("\b");
 
    printf("%d ",time);
 
 }
}

int main()
{
 printf("Enter Time Quanta: ");
 scanf("%d",&tq);
 printf("Enter Total Number of Process: ");
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
  {
   p[i].pid=i+1;
   printf("Enter Arrival Time of Process %d: ",i+1);
   scanf("%d",&p[i].at);
   printf("Enter Burst Time of Process %d: ",i+1);
   scanf("%d",&p[i].bt);
  }
 sort();
 compute();
 table();
 ganttchart();
 printf("\n\nAvarage Waiting Time=%.2f\nAvarage Turn Around Time=%.2f\n",avgwt,avgtat);
 
}
