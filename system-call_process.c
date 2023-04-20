#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
 int status;
 int cpid;
 int pid_c;
 if((cpid=fork())==-1){
  printf("\nCant fork\n");
 }
 else if(cpid==0){
  printf("Hello");
  execl("/bin/ls","ls","-l","-a",NULL);
  exit(0);
 }
 else{
  pid_c=wait(&status);
  printf("\nThis is parent with pid=%d\n",getpid());
  printf("\nChild with pid=%d completed successfully and statis is %d\n",pid_c,status);
 }
 return(0);
}
