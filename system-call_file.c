#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
int main(){
 char path[50];
 struct stat *nf;
 nf=(struct stat*)malloc(sizeof(struct stat));
 printf("\nEnter file name=\n");
 scanf("%s",path);
 stat(path,nf);
 printf("Pgm inode no=%ld\n",nf->st_ino);
 printf("Pgm size=%ld\n",nf->st_blksize);
 printf("Access time=%s\n",ctime(&nf->st_atime));
 printf("Modified Time=%s\n",ctime(&nf->st_mtime));
 printf("Protection=%d\n",nf->st_mode); 
 printf("User id=%d\n",nf->st_uid);
 printf("Group id=%d\n",nf->st_gid);
 printf("Device driver no=%ld\n",nf->st_nlink);
 return(0);
}  
