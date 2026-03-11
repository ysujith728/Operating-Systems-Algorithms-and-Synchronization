#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
key_t key=ftok("shmem",65);
int shmid=shmget(key,1024,0666);
char *data=(char*)shmat(shmid,NULL,0);
printf("data read from shared mem:%s",data);
return 0;
}
