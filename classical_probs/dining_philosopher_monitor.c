#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t mutex;
pthread_cond_t cond[N];

int state[N]; // 0=thinking 1=hungry 2=eating

void test(int i){
    if(state[i]==1 &&
       state[(i+4)%N]!=2 &&
       state[(i+1)%N]!=2){
        state[i]=2;
        pthread_cond_signal(&cond[i]);
    }
}

void take_forks(int i){
    pthread_mutex_lock(&mutex);

    state[i]=1;
    printf("Philosopher %d is hungry\n",i);

    test(i);

    while(state[i]!=2)
        pthread_cond_wait(&cond[i],&mutex);

    pthread_mutex_unlock(&mutex);
}

void put_forks(int i){
    pthread_mutex_lock(&mutex);

    state[i]=0;

    test((i+4)%N);
    test((i+1)%N);

    pthread_mutex_unlock(&mutex);
}

void* philosopher(void* arg){
    int id=*(int*)arg;

    while(1){
        printf("Philosopher %d thinking\n",id);
        sleep(1);

        take_forks(id);

        printf("Philosopher %d eating\n",id);
        sleep(2);

        put_forks(id);
    }
}

int main(){

    pthread_t phil[N];
    int id[N];

    pthread_mutex_init(&mutex,NULL);

    for(int i=0;i<N;i++)
        pthread_cond_init(&cond[i],NULL);

    for(int i=0;i<N;i++){
        id[i]=i;
        pthread_create(&phil[i],NULL,philosopher,&id[i]);
    }

    for(int i=0;i<N;i++)
        pthread_join(phil[i],NULL);

    return 0;
}