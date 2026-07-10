#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();

    if(pid == 0){
        printf("Child Process\n");
        printf("Child Process id is : %d \n",getpid());
        exit(0);
    }
    else
    {
        printf("Parent process\n");
        printf("Parent Process id is : %d \n",getpid());
        int status = 0x00;
        pid_t cpid = wait(&status);
        printf("The child pid is %d and status is %d\n",cpid,status);
        if((status && 0xff) != 0){
            printf("Process terminated abnormally\n");
        }
        else{
            printf("Process terminated normally\n");
        }
    }

    return 0;
}