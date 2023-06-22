#include<stdio.h>
#include<stdlib.h>

int m,p,bw=0,ww=0,fw=0;
int me[10],pr[10],ordm[10],ordp[10];
int me1[10],pr1[10],ordm1[10],ordp1[10];
int me2[10],pr2[10],ordm2[10],ordp2[10];

void First()
{
int a=0;
int flag=0;
for(int i=0;i<p;i++)
{
	for(int j=0;j<m;j++)
	{
		if(me1[j]>pr1[i])
		{
			ordm1[a]=j+1;
			ordp1[a]=i+1;
			a++;	
			fw+=me1[j]-pr1[i];	
			me1[j]=0;	
			flag=1;
			break;	
		}	
	}


}
for(int i=0;i<m;i++)
{
	if(me1[i]!=0)
	fw+=me1[i];
}
for(int i=0;i<a;i++)
{
	printf("M[%d] ---------> P[%d]\n",ordm1[i],ordp1[i]);
}
}

void Worst()
{
int a=0;
int diff=0,d,flag=0,temp1,temp2;
for(int i=0;i<p;i++)
{
	d=0;
	flag=0;
	for(int j=0;j<m;j++)
	{
		diff=me2[j]-pr2[i];
		if(d<diff)
		{
			d=diff;
			temp1=i;
			temp2=j;
			flag=1;
		}	
	}
	if(me2[temp2]>pr2[temp1] && flag!=0)
	{
		ordm2[a]=temp2+1;
		ordp2[a]=temp1+1;
		a++;	
		ww+=me2[temp2]-pr2[temp1];	
		me2[temp2]=0;		
	}

}
for(int i=0;i<m;i++)
{
	if(me2[i]!=0)
	ww+=me2[i];
}
for(int i=0;i<a;i++)
{
	printf("M[%d] ---------> P[%d]\n",ordm2[i],ordp2[i]);
}
}


void Best()
{
int a=0;
int diff,d,flag=0,temp1,temp2;
for(int i=0;i<p;i++)
{
	for(int x=0;x<m;x++)
	{
		if(me[x]!=0)
		{
			d=me[x];
			break;
		}
	}

	flag=0;

	for(int j=0;j<m;j++)
	{
		if(me[j]==0)
		continue;

		diff=me[j]-pr[i];
		if(diff<d && diff >0)
		{
			d=diff;
			temp1=i;
			temp2=j;
			flag=1;
		}	

	}

	if(me[temp2]>pr[temp1] && flag!=0)
	{
		ordm[a]=temp2+1;
		ordp[a]=temp1+1;
		a++;	
		bw+=me[temp2]-pr[temp1];	
		me[temp2]=0;		
	}


}
for(int i=0;i<m;i++)
{
	if(me[i]!=0)
	bw+=me[i];
}
for(int i=0;i<a;i++)
{
	printf("M[%d] ---------> P[%d]\n",ordm[i],ordp[i]);
}
}


void main()
{
	int ch;
	printf("Enter Number of Memory Blocks: ");
	scanf("%d",&m);
	printf("\n\n-----Size of Memory-----\n");
	for(int i=0;i<m;i++)
	{
		printf("Enter Size of Memory Block %d: ",i+1);
		scanf("%d",&me[i]);
		me1[i]=me[i];
		me2[i]=me[i];
	}
	printf("---------------------");
	printf("\n\nEnter Number of Processes: ");
	scanf("%d",&p);
	printf("\n\n-----Size of Processes-----\n");
	for(int i=0;i<p;i++)
	{
		printf("Enter Size of Process %d: ",i+1);
		scanf("%d",&pr[i]);
		pr1[i]=pr[i];
		pr2[i]=pr[i];
	}

	printf("\n\n\n\nFirst Fit\n");
	First();
	printf("\n\n\n\nBest Fit\n");
	Best();
	printf("\n\n\n\nWorst Fit\n");	
	Worst();
	printf("\n\n\n\nThe Wasteage of Memory is as follows:-\nBest Fit - %d(Bits)\nWorst Fit - %d(Bits)\nFirst Fit - %d(Bits)\n",bw,ww,fw);
	if(bw<ww && bw<<fw)
	printf("Hence Best Fit is the Best!!\n");
	else if(ww<bw && ww<<fw)
	printf("Hence Best Fit is the Best!!\n");
	else if(fw<ww && fw<<bw)
	printf("Hence Best Fit is the Best!!\n");

}
