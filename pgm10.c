#include <stdio.h>

int processes[10];
int available[10];
int max[10][10];
int allocation[10][10];
int need[10][10];
int request[10];
int n, m,flag=1,l=1;

void calc()				
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void printmat()
{
printf("\nMax\n");
for (int i = 0; i < n; i++) 
{
        for (int j = 0; j < m; j++) 
        {
	printf("%d  ",max[i][j]);
        }
        printf("\n");
    }

printf("\nAvailable\n");
for (int i = 0; i < n; i++) 
{
    printf("%d  ",available[i]);
}
printf("\n");

printf("\nAllocation\n");
for (int i = 0; i < n; i++) 
{
        for (int j = 0; j < m; j++) 
        {
	printf("%d  ",allocation[i][j]);
        }
        printf("\n");
    }
printf("\n");

printf("\nNeed\n");
for (int i = 0; i < n; i++) 
{
        for (int j = 0; j < m; j++) 
        {
	printf("%d  ",need[i][j]);
        }
        printf("\n");
    }
printf("\n");
}

void Safe()
{
    int finish[10];
    for(int i=0;i<n;i++)
    finish[i]=0;

    int safeSequence[10];
    int work[10];
    for (int i = 0; i < m; i++) {
        work[i] = available[i];
    }
    int count = 0;
    while (count < n) {
        int found = 0;
        for (int p = 0; p < n; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j])
                        break;
                }
                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allocation[p][k];
                    }
                    safeSequence[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("System is not in a safe state\n");
        }
    }
    printf("System is in a safe state\nSafe sequence is = ");
    for (int i = 0; i < n - 1; i++) {
        printf("P%d -> ", safeSequence[i]);
    }
    printf("P%d\n", safeSequence[n - 1]);
}



void main()
{
    int req;
    int s;
    printf("Enter the number of processes = ");
    scanf("%d", &n);
    printf("Enter the number of resources = ");
    scanf("%d", &m);

    printf("Enter the available resources\n");
    for (int i = 0; i < m; i++) {
        printf("For Resource %d: ",i);
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
	printf("For Process %d Resource %d = ",i,j);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix =\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
	printf("For Process %d Resource %d = ",i,j);
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\n");
    calc();
    printmat();
    Safe();
    while(l)
    {
    printf("\nDo you wish to Request some resources for a Perticular Process(1/0)? = ");
    scanf("%d",&s);
    if(s==1)
    {
    	printf("Which Process do u wish to request for (%d -> %d)? = ",0,n);
	scanf("%d",&req);
	for(int i=0; i<m;i++)
	{
		printf("How Many of Resource %d? = ",i);
		scanf("%d",&request[i]);
	}
	flag=1;
	for(int i=0; i<m;i++)
	{
		if(available[i]<request[i])
		{
			flag=2;
		}
		else 
		{
		available[i]-=request[i];
		allocation[req][i]+=request[i];
		}		
		if(request[i]>need[req][i])
		{
			flag=3;
		}
	}
	if(flag==1)
	{
	printf("New Calculations!\n");
	calc();
    	printmat();
    	Safe();
	}    
	else if(flag==2)
		printf("The Requested Resources exceed Availability!\n");
	else if(flag==3)
		printf("You Cannot Request more than needed!\n");
   }
   else if(s==0)
	l=0;
   else
   printf("<>Program ending<>\n");
   }
}
