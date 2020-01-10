

#include<stdio.h>

#include<stdlib.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<netdb.h>

#define server_ip "127.0.0.1"

void error(char *msg)

{

	perror(msg);

	exit(0);

}

void main(int argc,char *argv[])

{

	int sockfd,port_no,n;

	struct sockaddr_in serv_addr;

	//struct hostent *server;

	char buffer[256];

	/*if(argc<2)

	{

		fprintf(stderr,"usage %s hostname port",argv[0]);

		exit(0);

	}*/

	port_no=atoi(argv[1]);

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	if(sockfd<0)

	error("error opening socket");

	/*server=gethostbyname(argv[1]);

	if(server==NULL)

	{

		fprintf(stderr,"error ,no such host");
	
		exit(0);

	}*/

	
	

		bzero((char *) &serv_addr,sizeof(serv_addr));

		serv_addr.sin_family=AF_INET;

		//bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,);

		serv_addr.sin_port=htons(port_no);

		serv_addr.sin_addr.s_addr=inet_addr(server_ip);

		if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)

		error("error connecting");
	
	while(1)

	{

		printf("\npls enter msg");

		bzero(buffer,256);

		fgets(buffer,256,stdin);

		n=write(sockfd,buffer,strlen(buffer));

		if(n<0)

			error("\nerror in writing");

		bzero(buffer,256);

		n=read(sockfd,buffer,255);

		if(n<0)

			error("error in reading");

		printf("%s \n",buffer);

	}

} 
