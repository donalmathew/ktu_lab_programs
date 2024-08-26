					//stop and wait receiver

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
int sockfd;
struct sockaddr_in serveraddr;
char buffer[1024];

int frame_id = 0;
frame frame_send;
frame frame_recv;

sockfd = socket(AF_INET,SOCK_DGRAM,0);

serveraddr.sin_family = AF_INET;
serveraddr.sin_port = htons(6666);
serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

while(1)
{
socklen_t addr_size = sizeof(serveraddr);
int f_recv_size = recvfrom(sockfd,&frame_recv,sizeof(frame),0,(struct sockaddr*)&newaddr,&addr_size);
if(f_recv_size > 0 && frame_recv.frame_kind == 1 && frame_recv.seq_no == frame_id)
{
printf("[+]Frame receved: %s\n",frame_recv.packet.data);

frame_send.seq_no = 0;
frame_send.frame_kind = 0;
frame_send.ack = frame_recv.seq_no+1;

sendto(sockfd,&frame_send,sizeof(frame),0,(struct sockaddr*)&newaddr,addr_size);
printf("[+]Ack send\n");
}
else
{
printf("[+]Frame not receved\n");
}
frame_id++;
}
close(sockfd);
}
