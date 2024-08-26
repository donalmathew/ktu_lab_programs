					// tcp server

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(void)
{

struct sockaddr_in server_addr, client_addr;
char server_message[2000], client_message[200];

int socket_desc = socket(AF_INET,SOCK_STREAM,0);
printf("server socket created successfully \n");

server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(2000);
server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

bind(socket_desc,(struct sockaddr*)&server_addr,sizeof(server_addr));
printf("bind to port number \n");

listen(socket_desc,1);
printf("listening------------\n");

int client_size=sizeof(client_addr);
int client_sock=accept(socket_desc,(struct sockaddr *)&client_addr,&client_size);

if(recv(client_sock,client_message,sizeof(client_message),0)<0)
{
printf("could not receive");
return -1;
}
printf("message from client is %s\n",client_message);

strcpy(server_message,"this is servers message");

if(send(client_sock,server_message,strlen(server_message),0)<0)
{
printf("cannot send");
return -1;
}

recv(client_sock,client_message,sizeof(client_message),0);
printf("message from client is %s\n",client_message);

strcpy(server_message,"manoj b c");
send(client_sock,server_message,strlen(server_message),0);

close(client_sock);
close(socket_desc);
return 0;
}
