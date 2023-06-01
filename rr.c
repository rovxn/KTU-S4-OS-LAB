#include<stdio.h>
#include<string.h>
struct process{
char name[10];
int at;
int bt;
int ct;
int rbt;
}p[10],ready[10],c[10],temp;
int tq,front=0,rear=0,crear=-1;
void round(int n);
void main()
{
int n,i,j;
printf("Enter the number of process and tq\n");
scanf("%d%d",&n,&tq);
for(i=0;i<n;i++)
{
printf("Enter the name,bt,at\n");
scanf("%s%d%d",p[i].name,&p[i].bt,&p[i].at);
p[i].rbt=p[i].bt;
}
for(i=0;i<n;i++)
{

for(j=0;j<n-1;j++)
{
if(p[j].at>p[j+1].at)
{
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}

round(n);
}
void round(int n)
{

int tot=0,i,ft,start,k=0,j,wt=0,tat=0;
ready[front]=p[k++];
while(front<=rear)
{
if(ready[front].rbt<=tq){
ready[front].ct=tot+ready[front].rbt;
ready[front].rbt=0;
c[++crear]=ready[front];

tot=ready[front].ct;
if(k<n)
ready[++rear]=p[k++];

}
else{
ready[front].ct=tot+tq;
ready[front].rbt=ready[front].rbt-tq;
tot=ready[front].ct;
for(i=k;i<n;i++)
{
if(p[i].at<=ready[front].ct)
{
ready[++rear]=p[i];
k++;
}
}
if(ready[front].rbt>0)
ready[++rear]=ready[front];
else
c[++crear]=ready[front];
}
front++;
}
printf("Process\t\tArrivat_time\t\tBurst_time\t\tTurnaround_time\t\twaiting time\n\n");
for(i=0;i<n;i++)
{
printf("%s\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t%d\n\n",c[i].name,c[i].at,c[i].bt,(c[i]
.ct-c[i].at),((c[i].ct-c[i].at)-c[i].bt));
wt=wt+(c[i].ct-c[i].at)-c[i].bt;
tat=tat+(c[i].ct-c[i].at);
}

printf("\n\n");
printf("\nGantt Chart\n\n");
for(i=0;i<=rear;i++)
{
j=0;
printf(" ___");
for(j=0;j<tq;j++)
printf("__");
}
printf("\n");
printf("|");
for(i=0;i<=rear;i++)
{
printf(" %s",ready[i].name);
j=0;

for(j=0;j<tq;j++)
printf("__");
printf("|");
}
printf("\n");
printf("0");
for(i=0;i<=rear;i++)
{
printf(" ");
j=0;
for(j=0;(tq>=ready[i].ct)?j<ready[i].ct:j<tq;j++)
printf(" ");

printf("%d",ready[i].ct);
}
printf("\n\n");
printf("avg wt = %.2f\n",((float)wt/(float)n));
printf("avg tat = %.2f\n",((float)tat/(float)n));

printf("\n\n");

}