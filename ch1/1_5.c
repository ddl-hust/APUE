#include"apue.h"

#include<errno.h>

int main(int argc, char*argv[]){
    fprintf(stderr, "EACESS :%s \n",strerror(EACCES));
    errno=ENOENT;
    perror(argv[0]); //设置了errno 之后perror解释了当前errno的含义
  
    printf("current pid:%ld\n",(long)getpid());
      exit(0);

}