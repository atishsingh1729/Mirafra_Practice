#define _XOPEN_SOURCE 700


#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


typedef struct employee{
    char name[10];
    int empID;
}employee_t;

typedef struct result{
    float sum;
    float prod;
}result_t;

int counter = 0;
int count;
int data_ready = 0; 
int sharedData = 0;
int spinCounter = 0;

pthread_mutex_t lock;
pthread_mutexattr_t attr;
pthread_cond_t con;
pthread_rwlock_t rwlock;
pthread_spinlock_t spinLock;


void *thread1(void* args){

    employee_t *emp = (employee_t*)args;
    while(1){
        printf("Employee name is %s\n",emp->name);
        printf("Employee ID is %d\n",emp->empID);
        sleep(1);
    }
    return NULL;
}

void *thread2(void* args){
    int j = 0;
    while(1){
        printf("Thread 2 executing count = %d \n",j);
        sleep(1);
        j++;
    }
    return NULL;
}

void *thread3(void *args){

    result_t *res = (result_t*)malloc(sizeof(result_t));

    printf("In thread number 3 \n");
    res->sum = 5+10;
    res->prod = 5*10;
    pthread_exit(res);

}


void *thread4(void *args){
    for(int i =0;i<100000;i++){
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void *thread5(void *args){
    for(int i = 0;i<100000;i++){
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}


void *prodThread(void *args){

    sleep(3);
    pthread_mutex_lock(&lock);
    count++;
    data_ready = 1;
    printf("Data Produced Succesfully \n");
    pthread_cond_signal(&con);
    pthread_mutex_unlock (&lock);

    return NULL;
    
}




void *consumerThread(void *args){
    
    pthread_mutex_lock(&lock);
    while(data_ready == 0){
        printf("Consumer: Waiting...\n");
        pthread_cond_wait(&con,&lock);
    }
    printf("Count value from prod thread is Received ---->  %d \n",count);
    pthread_mutex_unlock(&lock);
    return NULL;
}


void* readerThread(void *args){
    while(1){
        int id = *(int*)args;
        pthread_rwlock_rdlock(&rwlock);
        sleep(2);
        printf("Reader task id[%d] and value %d \n",id,sharedData);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
    return NULL;
}

void *writerThread(void *args){
    while (1)
    {
        pthread_rwlock_wrlock(&rwlock);
        printf("Writer Task is writing\n");
        sharedData++;
        sleep(3);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    
    }
    return NULL;
}

void *worker(void* args){
    
    
    for(int i = 0;i<10000;i++){
        pthread_spin_lock(&spinLock);
        spinCounter++;
        pthread_spin_unlock(&spinLock);
    }
    
    return NULL;
}



int main(){

    pthread_t tid1,tid2,tid3,tid4,tid5,tid6,tid7,tid8,tid9,tid10,tid11,tid12;
    employee_t emp1;
    strcpy(emp1.name,"Atish");
    emp1.empID = 7306;

    int id1 = 1,id2 = 2;

    result_t *res  = (result_t*)malloc(sizeof(result_t));

    pthread_mutexattr_init(&attr);

    pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&lock,&attr);

    pthread_cond_init(&con,NULL);

    pthread_rwlock_init(&rwlock,NULL);

    pthread_spin_init(&spinLock,PTHREAD_PROCESS_PRIVATE);

    printf("In main thread\n");
   // pthread_create(&tid1,NULL,thread1,&emp1);
   // pthread_create(&tid2,NULL,thread2,NULL);
   // pthread_create(&tid3,NULL,thread3,NULL);
    //pthread_create(&tid4,NULL,thread4,NULL);
    //pthread_create(&tid5,NULL,thread5,NULL);
   // pthread_join(tid3,(void**)&res);

    //printf("Result of sum is ------------------------>%0.2f \n",res->sum);
    //printf("Result of prod is ------------------------>%0.2f \n",res->prod);
    //pthread_join(tid1,NULL);
    //pthread_join(tid2,NULL);
    //pthread_join(tid4,NULL);
    //pthread_join(tid5,NULL);

    printf("counter is ----> %d\n",counter);

    //prod and consumer threads
    //pthread_create(&tid6,NULL,prodThread,NULL);
    //pthread_create(&tid7,NULL,consumerThread,NULL); 

    //pthread_join(tid6,NULL);
    //pthread_join(tid7,NULL);


    //read lock
    //pthread_create(&tid8,NULL,readerThread,&id1);
    //pthread_create(&tid9,NULL,readerThread,&id2);
    //pthread_create(&tid10,NULL,writerThread,NULL);

    //pthread_join(tid8,NULL);
    //pthread_join(tid9,NULL);
    //pthread_join(tid10,NULL);


    //spinlock
    pthread_create(&tid11,NULL,worker,NULL);
    pthread_create(&tid12,NULL,worker,NULL);

    pthread_join(tid11,NULL);
    pthread_join(tid12,NULL);

    printf("Spincounter = %d \n",spinCounter);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&con);
    pthread_rwlock_destroy(&rwlock);\
    pthread_spin_destroy(&spinLock);

    return 0;
}