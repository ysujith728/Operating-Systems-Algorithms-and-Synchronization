#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
int fd1,fd2;
char msg[100],buffer[100];

mkfifo("fifo1",0666);
mkfifo("fifo2",0666);
fd1=open("fifo1",O_WRONLY);
fd2=open("fifo2",O_RDONLY);
printf("Enter message for Process 2: ");
fgets(msg,sizeof(msg),stdin);
write(fd1,msg,strlen(msg)+1);
read(fd2,buffer,sizeof(buffer));
printf("message read from process 2:%s\n",buffer);
close(fd1);
close(fd2);
return 0;

}


