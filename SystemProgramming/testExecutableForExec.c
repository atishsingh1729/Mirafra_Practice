#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc,char *argv[]){
    if(argc > 0){
        printf("The argument counts are = %d \n",argc);
        for(int i = 0;i<argc;i++){
            printf("The arguments in index[%i] is %s \n",i,argv[i]);
        }
        printf("The process ID of this Process will be the the same %d \n",getpid());
    }
}