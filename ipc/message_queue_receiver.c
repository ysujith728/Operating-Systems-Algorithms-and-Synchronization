#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_buffer{
long mesg_type;
char mesg_text[100];
}message;

int main(){
key_t key=ftok("msgpassingmem",65);
int msgid=msgget(key,0666);
msgrcv(msgid,&message,sizeof(message),1,0);
printf("data received is: %s \n",message.mesg_text);
msgctl(msgid,IPC_RMID,NULL);
return 0;
}

