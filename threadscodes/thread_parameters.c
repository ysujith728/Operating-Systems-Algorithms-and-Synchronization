#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* routine(void* arg) {

    sleep(1);

    int index = *(int*)arg;

    printf("%d ", primes[index]);

    return NULL;
}

int main() {

    pthread_t th[10];
    int indices[10];

    for (int i = 0; i < 10; i++) {

        indices[i] = i;

        pthread_create(&th[i], NULL, &routine, &indices[i]);
    }

    for (int i = 0; i < 10; i++) {

        pthread_join(th[i], NULL);
    }

    printf("\n");

    return 0;
}