#include "apue.h"
#include <unistd.h>
#define  BUFSIZE 4096
int main(){

    char buf[BUFSIZ];
    int n;
    while((n=read(STDIN_FILENO,buf,BUFSIZ))>0)
        if(write(STDOUT_FILENO,buf,n)!=n) err_sys("write error");
    if(n<0) err_sys("read error");
    exit(0);
}