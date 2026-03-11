#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* roll_dice() {

    int value = (rand() % 6) + 1;

    int* result = malloc(sizeof(int));

    *result = value;

    sleep(2);

    printf("Thread result: %d\n", value);

    pthread_exit((void*) result);
}

int main(int argc, char* argv[]) {

    int* res;

    srand(time(NULL));

    pthread_t th;

    pthread_create(&th, NULL, &roll_dice, NULL);

    pthread_join(th, (void**) &res);

    printf("Result: %d\n", *res);

    free(res);

    return 0;
}