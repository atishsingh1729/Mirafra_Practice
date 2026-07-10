#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define MAX_MSG_LEN 100

struct message{
    long mType;
    char mText[MAX_MSG_LEN];
};




int main(void){
    
    key_t key = 1234;
    int msgid = msgget(key,IPC_CREAT|0666);

    if(msgid == -1){
        perror("failed msg id creation\n");
        return 1;
    }

    struct message msg;
    msg.mType = 1;

    fgets(msg.mText,sizeof(msg.mText),stdin);

    if(msgsnd(msgid,&msg,sizeof(msg.mText),0) == -1){
        perror("msgsend error\n");
        return 1;
    }

    printf("Message sent succesfully\n");

    return 0;
}