#include <stdio.h>
#include <pthread.h>

typedef struct{
    int counter;
    pthread_mutex_t lock;
}CounterMonitor;

CounterMonitor mon;

void init_monitor(CounterMonitor *m){
    m->counter = 0;
    pthread_mutex_init(&m->lock,NULL);
}

void increment(CounterMonitor *m){
    pthread_mutex_lock(&m->lock);
    m->counter++;
    pthread_mutex_unlock(&m->lock);
}

void *update(void *args){

    for(int i=0;i<100000000;i++){
        increment(&mon);
    }

    return NULL;
}

int main(){

    pthread_t t1,t2;

    init_monitor(&mon);

    pthread_create(&t1,NULL,update,NULL);
    pthread_create(&t2,NULL,update,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Final counter = %d\n",mon.counter);

    pthread_mutex_destroy(&mon.lock);

    return 0;
}