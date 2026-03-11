#include <stdio.h>
#include <unistd.h>

int main(){

    pid_t pid = fork();

    if(pid == 0){
        printf("Child process finished\n");
    }
    else{
        sleep(20);
        printf("Parent process running\n");
    }

    return 0;
}