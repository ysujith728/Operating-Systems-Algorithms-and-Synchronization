#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

int results[2];

void* routine(void* arg) {

    int index = *(int*)arg;
    int sum = 0;

    for (int j = 0; j < 5; j++) {
        sum += primes[index + j];
    }

    printf("Local sum: %d\n", sum);

    if (index == 0)
        results[0] = sum;
    else
        results[1] = sum;

    return &results[index / 5];
}

int main() {

    pthread_t th[2];
    int indices[2] = {0,5};

    for (int i = 0; i < 2; i++) {
        pthread_create(&th[i], NULL, routine, &indices[i]);
    }

    int globalSum = 0;

    for (int i = 0; i < 2; i++) {

        int* r;

        pthread_join(th[i], (void**)&r);

        globalSum += *r;
    }

    printf("Global sum: %d\n", globalSum);

    return 0;
}