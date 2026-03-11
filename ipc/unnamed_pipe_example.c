#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define buffer 50

int main(){
pid_t pid;
int fd[2];
if(pipe(fd)==-1) printf("failure in pipe");
char write_msg[]="demo msgggggg";
char read_msg[buffer];
pid=fork();
if(pid>0){
printf("this is parent process\n");
close(fd[0]);
write(fd[1],write_msg,strlen(write_msg)+1);
close(fd[1]);
}
else{
printf("this is child process\n");
close(fd[1]);
read(fd[0],read_msg,buffer);
printf("read %s\n",read_msg);
close(fd[0]);

}
return 0;
}
