#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

#define CONNECTION_QUEUE_DEPTH 5

int main(){
    int server_fd,client_fd;
    struct sockaddr_in server;

    server_fd = socket(AF_INET,SOCK_STREAM,0);

    if(server_fd == -1){
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(server_fd, (const struct sockaddr *)&server, (socklen_t)sizeof(server)) <0){
        perror("bind");
        return 1;
    }

    listen(server_fd,CONNECTION_QUEUE_DEPTH);

    printf("Listening for clients \n");

    client_fd = accept(server_fd,NULL,NULL);//blocking

    printf("Client Connected\n");

    char buffer[100];

    recv(client_fd,buffer,sizeof(buffer),0);

    printf("Received from Client : %s\n",buffer);

    char reply[] = "This is Server\n";
    
    send(client_fd,reply,sizeof(reply),0);

    close(client_fd);
    close(server_fd);
}