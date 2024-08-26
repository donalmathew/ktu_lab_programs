				// stop and wait sender

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

typedef struct packet
{
char data[1024];
}packet;

typedef struct frame
{
int frame_kind;
int seq_no;
int ack;
packet packet;
}frame;

void main()
{

struct sockaddr_in serveraddr;
char buffer[1024];

int frame_id = 0;
frame frame_send;
frame frame_recv;
int ack_recv = 1;

int sockfd = socket(AF_INET,SOCK_DGRAM,0);

serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(6666);
serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

while(1)
{
if(ack_recv=1)
{
frame_send.seq_no = frame_id;
frame_send.frame_kind = 1;
frame_send.ack=0;
printf("enter data:");
scanf("%s",buffer);
strcpy(frame_send.packet.data,buffer);
sendto(sockfd,&frame_send,sizeof(frame),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("[+]frame send\n");
}
int addr_size = sizeof(serveraddr);
int f_recv_size = recvfrom(sockfd,&frame_recv,sizeof(frame),0,(struct sockaddr*)&serveraddr,&addr_size);
if(f_recv_size > 0 && frame_recv.seq_no == 0 && frame_recv.ack == frame_id+1)
{
printf("[+]Ack received\n");
ack_recv = 1;
}
else 
{
printf("[+]Ack not receved\n");
ack_recv = 0;
}
frame_id++;
}
close(sockfd);
}
