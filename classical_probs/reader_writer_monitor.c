#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

int read_count=0;
int writing=0;

void* reader(void* arg){

    int id=*(int*)arg;

    pthread_mutex_lock(&mutex);

    while(writing)
        pthread_cond_wait(&cond,&mutex);

    read_count++;

    pthread_mutex_unlock(&mutex);

    printf("Reader %d reading\n",id);
    sleep(1);

    pthread_mutex_lock(&mutex);

    read_count--;

    if(read_count==0)
        pthread_cond_signal(&cond);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* writer(void* arg){

    int id=*(int*)arg;

    pthread_mutex_lock(&mutex);

    while(read_count>0 || writing)
        pthread_cond_wait(&cond,&mutex);

    writing=1;

    pthread_mutex_unlock(&mutex);

    printf("Writer %d writing\n",id);
    sleep(2);

    pthread_mutex_lock(&mutex);

    writing=0;

    pthread_cond_broadcast(&cond);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(){

    pthread_t r[3],w[2];
    int id[5];

    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);

    for(int i=0;i<3;i++){
        id[i]=i+1;
        pthread_create(&r[i],NULL,reader,&id[i]);
    }

    for(int i=0;i<2;i++){
        id[i]=i+1;
        pthread_create(&w[i],NULL,writer,&id[i]);
    }

    for(int i=0;i<3;i++) pthread_join(r[i],NULL);
    for(int i=0;i<2;i++) pthread_join(w[i],NULL);

    return 0;
}