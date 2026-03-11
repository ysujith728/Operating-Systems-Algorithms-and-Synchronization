#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void* routine(){
    printf("Test from threads\n");
}

int main(int argc,char* argv[]){
pthread_t t1;
pthread_create(&t1,NULL,&routine,NULL);
pthread_join(t1,NULL);
return 0;
}


