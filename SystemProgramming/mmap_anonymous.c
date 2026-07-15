#include <stdio.h>
#include <sys/mman.h>

int main(){

    int *ptr = (int *)mmap(NULL,10*sizeof(int),PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);

    if(ptr==MAP_FAILED){
        perror("mmap");
    }

    for(int i = 0;i<10;i++){
        ptr[i] = i*10;
    }

    for(int j=0;j<10;j++){
        printf("Numbers are at index[%d] = %d\n",j,ptr[j]);
    }

    munmap(ptr,sizeof(int)*10);

    return 0;
}