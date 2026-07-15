#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
    int sockfd;
    struct sockaddr_in server;

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    if(sockfd == -1){
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    inet_pton(AF_INET,"127.0.0.1",&server.sin_addr);

    connect(sockfd,(struct sockaddr*)&server,sizeof(server));

    send(sockfd,"HELLO SERVER",13,0);

    char buffer[100];

    recv(sockfd,buffer,sizeof(buffer),0);

    printf("Received from Server : %s ",buffer);

    close(sockfd);

    return 0;
}