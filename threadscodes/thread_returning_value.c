#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void* routine(){
    printf("Test from threads\n");
    return "Thread finished successfully";
}

int main(int argc,char* argv[]){
pthread_t t1;
void *status;
pthread_create(&t1,NULL,&routine,NULL);
pthread_join(t1,&status);
printf("Thread returned: %s\n", (char*)status);
return 0;
}