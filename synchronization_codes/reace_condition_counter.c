#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *increment(void *args){
    for(int i=0;i<10000000;i++){
        counter++;
    }
    return NULL;
}

int main(){
    pthread_t t1,t2;

    pthread_create(&t1,NULL,increment,NULL);
    pthread_create(&t2,NULL,increment,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Final counter value = %d\n",counter);
    return 0;
}