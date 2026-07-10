#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd[2];
    
    pipe(fd);

    pid_t pid = fork();
    if(pid == 0){
        //child process
        close(fd[0]);//close read end
        int arr[10] = {1,2,3,4,5,6,7,8,9,10};

        for(int i = 0;i<10;i++)
            write(fd[1], &arr[i], sizeof(int));

        close(fd[1]);
    }
    else{
        char buffer[100];
        close(fd[1]);
        int a[10];
        for(int i = 0;i<10;i++){
            read(fd[0],&a[i],sizeof(int));
        }
        for(int i = 0;i<10;i++)
        printf("Received from child : %d\n",a[i]);
        close(fd[0]);
    }
    
    return 0;

}