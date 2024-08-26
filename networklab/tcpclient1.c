				// tcp client

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(void)
{

struct sockaddr_in server_addr;
char server_message[2000], client_message[200];

int socket_desc = socket(AF_INET,SOCK_STREAM,0);
printf("server socket created successfully \n");

server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(2000);
server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

if(connect(socket_desc,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
{
printf("unable to connect\n");
return -1;
}
printf("connected to server successfully\n");

printf("enter the message:");
fgets(client_message,sizeof(client_message),stdin);
 
if(send(socket_desc,client_message,strlen(client_message),0)<0)
{
printf("unable to send message");
return -1;
}

if(recv(socket_desc,server_message,sizeof(server_message),0)<0)
{
printf("error while receiving message\n");
return -1;
}
printf("message from server is %s\n",server_message);

strcpy(client_message,"manoj");
send(socket_desc,client_message,strlen(client_message),0);

recv(socket_desc,server_message,sizeof(server_message),0);
printf("message from server is %s\n",server_message);

close(socket_desc);
return 0;
}
