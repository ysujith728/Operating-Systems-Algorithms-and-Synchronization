#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
key_t key=ftok("shmem",65);
int shmid=shmget(key,1024,0666|IPC_CREAT);
char *data=(char*)shmat(shmid,NULL,0);
printf("Enter some text:");
fgets(data,1024,stdin);
printf("Data written to shared memory:%s",data);
shmdt(data);
return 0;
}
