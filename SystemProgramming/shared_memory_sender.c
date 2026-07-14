#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>

typedef struct report{
    long time;
    float temp;
}report_t;


int main(){
    sem_t *sem;

    key_t key = 1234;
    report_t *newReport;

    sem = sem_open("/my_sem1",O_CREAT,0666,1);

    int shmid = shmget(key,1024,IPC_CREAT|0666);

    if(shmid == -1){
        perror("shmgget error");
        return 1;
    }

    newReport = (report_t*)shmat(shmid,NULL,0);
  
    long i = 0;
    while(i<1000){
        sem_wait(sem);
         memcpy(&(newReport->time),&i,sizeof(long));
         printf("Data Written from Sender\n");
         sem_post(sem);
         sleep(1);
         i++;
    }
    
    return 0;


}