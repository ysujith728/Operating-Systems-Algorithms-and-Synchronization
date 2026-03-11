#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 

int read_count=0;
sem_t rw_mutex;
pthread_mutex_t mutex;

void *reader(void *arg){
int id=*(int*)(arg);
pthread_mutex_lock(&mutex);
read_count++;
if(read_count==1){
sem_wait(&rw_mutex);
}
pthread_mutex_unlock(&mutex);
printf("Reader %d is reading\n",id);
sleep(1);
pthread_mutex_lock(&mutex);
read_count--;
if(read_count==0){
sem_post(&rw_mutex);
}
pthread_mutex_unlock(&mutex);
return NULL;

}

void *writer(void *arg){
int id=*(int*)arg;
sem_wait(&rw_mutex);
printf("Writer %d is writing\n",id);
sleep(2);
sem_post(&rw_mutex);
return NULL;

}

int main(){
pthread_t r[3],w[2];
int id[5];
sem_init(&rw_mutex,0,1);
pthread_mutex_init(&mutex,NULL);

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
