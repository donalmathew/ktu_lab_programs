						// udp client

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void main()
{

struct sockaddr_in serveraddr;

char buffer[1024];

int sockfd = socket(AF_INET,SOCK_DGRAM,0);

serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(6666);
serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

strcpy(buffer,"hello udp server\n");
sendto(sockfd,buffer,1024,0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

int addr_size = sizeof(serveraddr);
recvfrom(sockfd,buffer,1024,0,(struct sockaddr*)&serveraddr,&addr_size);
printf("%s",buffer);

strcpy(buffer,"hello my name is client\n");
sendto(sockfd,buffer,1024,0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

recvfrom(sockfd,buffer,1024,0,(struct sockaddr*)&serveraddr,&addr_size);
printf("%s",buffer);

close(sockfd);

}
