				// time client

#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void main()
{
struct sockaddr_in servaddr;
char buf[1024];
time_t current_time;
int sfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
servaddr.sin_port = htons(5555);
strcpy(buf,"what is the time now server\n");
sendto(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
socklen_t addrlen = sizeof(servaddr);
recvfrom(sfd, &current_time, sizeof(current_time), 0, (struct sockaddr *)&servaddr, &addrlen);
printf("Server's Time: %s\n", ctime(&current_time));
}
