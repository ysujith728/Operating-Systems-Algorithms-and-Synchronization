#include <stdio.h>
#include <unistd.h>

int main(){

    pid_t pid = fork();

    if(pid == 0){
        sleep(5);
        printf("Child process\n");
        printf("Parent PID: %d\n",getppid());
    }
    else{
        printf("Parent exiting\n");
    }

    return 0;
}