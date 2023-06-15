#include <stdio.h>

int checkService(int avail[],int need[],int n){
    for(int i=0;i<n;i++){
        if(avail[i] < need[i])
            return 0;
    }
    return 1;
}

void main(){
    printf("Banker's Algorithm\n");
    printf("Enter the number of process: ");
    int n,r,i,j;
    scanf("%d",&n);
    printf("Enter the number of resources : ");
    scanf("%d",&r);
    int avail[r];
    printf("Enter the available resources vector\n");
    for(i=0;i<r;i++)
        scanf("%d",&avail[i]);
    int alloc[n][r];
    int max[n][r];
    int need[n][r];
    int alloc1[n][r];
    int max1[n][r];
    int need1[n][r];
    int avail1[n][r];
    printf("Enter the allocation matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
	    alloc1[i][j]=alloc[i][j];
        }
    }
    printf("Enter the max matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
	    max1[i][j]=max[i][j];
        }
    }
    printf("Need Matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            need[i][j] = max[i][j] - alloc[i][j];
	    need1[i][j]=need[i][j];
            printf("%2d ",need[i][j]);
        }
        printf("\n");
    }
    int count = 0;
    int flag[n];
    for(i=0;i<n;i++)
        flag[i] = 0;
    int test,temp[n];
    while(count<n){
        test = 0;
        for(i=0;i<n;i++){
            test++;
            if(checkService(avail,need[i],r) == 1 && flag[i] == 0){
                test = 0;
                temp[count] = i;
                count++;
                flag[i] = 1;
                for(j=0;j<r;j++){
                    avail[j] += alloc[i][j];
		    avail1[i][j]=avail[j];
                    need[i][j] = 0;
                    alloc[i][j] = 0;
                }
            }
        }
        if(test>2*n){
            printf("\nThere is no safe sequence\nDEADLOCK STATE\n");
            break;
        }
    }
		printf("PROCESS\tALLOCATION\tMAXIMUM\tAVAILABLE\tNEED\n");
                for(j=0;j<n;j++){
		    printf("P%d   ",j);
                    for(int k=0;k<r;k++){
                        printf("%2d   ",alloc1[j][k]);
                    }
                    for(int k=0;k<r;k++){
                        printf("%2d   ",max1[j][k]);
                    }
		    for(int k=0;k<r;k++){
                        printf("%2d   ",avail1[j][k]);
                    }
		    for(int k=0;k<r;k++){
                        printf("%2d   ",need1[j][k]);
                    }
		    printf("\n");
                }
                
    if(count==n){
        printf("\nSAFE SEQUENCE\n");
        for(i=0;i<n;i++){
	if(i<n-1)
	        printf("P%d => ",temp[i]);
	else
		printf("P%d ",temp[i]);		
        }
        printf("\n");
    }

}
