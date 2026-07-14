#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<stdlib.h>

typedef struct{
    long mType;
    char mText[100];
}message_t;

int main(){
    key_t key = 1234;

    int msgid = msgget(key,0666);

    if(msgid == -1){
        perror("msgid failed");
        exit(1);
    }
    message_t msg;

    if(msgrcv(msgid,&msg,sizeof(msg),1,0) == -1){
        perror("msg receive Failed");
        exit(1);
    }

    printf("Message Received was : %s \n",msg.mText);

}
