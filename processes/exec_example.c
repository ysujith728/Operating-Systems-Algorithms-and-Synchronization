#include <stdio.h>
#include <unistd.h>

int main(){

    printf("Before exec\n");

    execl("/bin/ls","ls",NULL);

    printf("This line will not execute\n");

    return 0;
}