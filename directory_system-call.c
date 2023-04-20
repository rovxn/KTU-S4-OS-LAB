#include<stdio.h>
#include<dirent.h>
void main(int argc,char *argv[]){
 printf("No. of arguments=%d and directory is %s\n",argc,argv[1]);
 DIR *dir;
 struct dirent *direntry;
 dir=opendir(argv[1]);
 while((direntry=readdir(dir))!=NULL)
  printf("%ld %s\n",direntry->d_ino,direntry->d_name);
 closedir(dir);
}  

