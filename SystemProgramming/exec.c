#include<stdio.h>
#include <unistd.h>


int main(){
    //execl
    printf("The process id of this process is %d \n",getpid());
    printf("This will run \n");
  //  execl("/home/mirafra/Documents/github/Mirafra_Practice/Mirafra_Practice/testExecutableForExec","-a","-l",NULL);
  //  printf("This must not run \n");
    //excvp
    char *argv[] = {"testExecutableForExec","-a","-l",NULL}; 

    execvp("./testExecutableForExec",argv);

    printf("This must not run\n");

    return 0;
}