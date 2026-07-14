#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>


typedef struct report{
    long time;
    float temp;
}report_t;


int main(){

    key_t key = 1234;
    report_t *rx_report;

    sem_t *sem;
    
    sem = sem_open("/my_sem1",0);

    int shmid = shmget(key,1024,IPC_CREAT|0666);
    
    if(shmid == -1){
        perror("shmget failed");
        return 1;
    }

    rx_report =(report_t*)shmat(shmid,NULL,0);
    
    while(rx_report->time < 1000){
        sem_wait(sem);
            printf("time = %lu \n",rx_report->time);
            sem_post(sem);
            sleep(1);
    }
    
    shmdt(rx_report);


    return 0;
}
