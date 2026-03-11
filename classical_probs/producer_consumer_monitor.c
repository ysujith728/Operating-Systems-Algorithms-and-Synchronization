#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int in=0,out=0,count=0;

pthread_mutex_t mutex;
pthread_cond_t not_full,not_empty;

void* producer(void* arg){

    for(int i=0;i<10;i++){

        pthread_mutex_lock(&mutex);

        while(count==SIZE)
            pthread_cond_wait(&not_full,&mutex);

        buffer[in]=i;
        printf("Produced %d\n",i);

        in=(in+1)%SIZE;
        count++;

        pthread_cond_signal(&not_empty);

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
}

void* consumer(void* arg){

    int item;

    for(int i=0;i<10;i++){

        pthread_mutex_lock(&mutex);

        while(count==0)
            pthread_cond_wait(&not_empty,&mutex);

        item=buffer[out];
        printf("Consumed %d\n",item);

        out=(out+1)%SIZE;
        count--;

        pthread_cond_signal(&not_full);

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
}

int main(){

    pthread_t p,c;

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&not_full,NULL);
    pthread_cond_init(&not_empty,NULL);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    return 0;
}