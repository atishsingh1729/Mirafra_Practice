#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

int main(){
    int fd;

    if(mkfifo("/tmp/myfifo",0666) == -1 && errno != EEXIST){
        perror("make fifo failed");\
        exit(1);
    }

    fd = open("/tmp/myfifo",O_WRONLY);
    if(fd == -1){
        perror("file descriptor open failed");
        exit(1);
    }
    char buffer[] = "Hello from Writer!!\n";
    write(fd,buffer,sizeof(buffer));

    close(fd);

    return 0;
}