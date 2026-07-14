#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MESSAGE_LEN 100

struct message{
    long mType;
    char mText[MAX_MESSAGE_LEN];
};


int main(){

    key_t key = 1234;

    int msgid  = msgget(key,0666);

    if(msgid== -1){
        perror("msgget");
    }

    struct message msg;

    if(msgrcv(msgid,&msg,sizeof(msg.mText),1,0) == -1){
        perror("msgrcv");
        return 1;
    }

    printf("Received message is : %s \n",msg.mText);

    return 0;
}