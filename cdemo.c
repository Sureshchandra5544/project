#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#define PORT 2020
#define server_ip "127.0.0.1"
#define max 100

int client()
{

	int sock_fd=0,msg_len=0;
	struct sockaddr_in servaddr;
	char buffer[max],*buffer1;
	buffer1=(char*)malloc(4*sizeof(char));
//	int buff;
	printf("hello");
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
        printf("\nSocket created");
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(server_ip);
	servaddr.sin_port=htons(PORT);
	connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	while(1){
		 read(sock_fd, buffer, sizeof(buffer));
                printf("\n%s",buffer);
		gets(buffer1);
		printf("pls come");
		write(sock_fd, buffer1, sizeof(buffer1));
	}
	close(sock_fd);
	return 0;
}
void main()
{
	client();
}
