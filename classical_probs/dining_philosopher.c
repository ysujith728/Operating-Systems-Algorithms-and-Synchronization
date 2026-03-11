#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

#define N 5
sem_t forks[N];

void *philosopher(void *arg){
int id=*(int*)arg;
while(1){
printf("philosopher %d thinking\n",id);
sleep(1);
sem_wait(&forks[id]);
sem_wait(&forks[(id+1)%N]);
printf("Philosopher %d eating \n",id);
sleep(2);

sem_post(&forks[id]);
sem_post(&forks[(id+1)%N]);

}
}

int main(){
pthread_t phil[N];
int id[N];
for(int i=0;i<N;i++){
sem_init(&forks[i],0,1);

}
for(int i=0;i<N;i++){
id[i]=i;
pthread_create(&phil[i],NULL,philosopher,&id[i]);
}

for(int i=0;i<N;i++){
pthread_join(phil[i],NULL);
}

return 0;
}


