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
fd1=open("fifo1",O_RDONLY);
fd2=open("fifo2",O_WRONLY);
read(fd1,buffer,sizeof(buffer));
printf("message from process1 is %s \n",buffer);
printf("Enter reply");
fgets(msg,sizeof(msg),stdin);
write(fd2,msg,strlen(msg)+1);
close(fd1);
close(fd2);
return 0;
}
