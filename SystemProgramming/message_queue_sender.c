#include<stdio.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

typedef struct message{
    long mType;
    char mText[100];
}message_t;




int main(){

    key_t key = 1234;

    int msgid = msgget(key,IPC_CREAT|0666);

    if(msgid == -1){
        perror("msgget failed");
        exit(1);
    }

    message_t newMsg;
    newMsg.mType = 1;
    strcpy(newMsg.mText,"Hello from the sender\n");

    if(msgsnd(msgid,&newMsg,sizeof(newMsg.mText),0) == -1){
        perror("message send failed");
        exit(1);
    }
    printf("Message sent succesfully\n");

    return 0;

}