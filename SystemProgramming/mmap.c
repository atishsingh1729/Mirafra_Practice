#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/mman.h>


int main(){
    
    int fd = open("/home/mirafra/Desktop/myfile.txt",O_RDWR);

    if(fd == -1){
        perror("open");
    }
    char* ptr = (char*)mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);

    if(ptr == MAP_FAILED){
        perror("mmap");
    }

    printf("The file contents are : %s\n",ptr);

    ptr[0] = 'X';

    printf("The file contents are : %s\n",ptr);

    munmap(ptr,100);

    close(fd);

    return 0;
}