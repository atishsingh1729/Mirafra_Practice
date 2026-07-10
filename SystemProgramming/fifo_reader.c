#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main(){
    int fd = open("/tmp/myfifo",0666);
    if(fd == -1){
        perror("unable to open");
            exit(1);
    }
    char str[50]; 
    read(fd,str,sizeof(str));
    printf("Received String is :  %s",str);
    unlink("/tmp/myfifo");

    return 0;
}