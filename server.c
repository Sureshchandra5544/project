#include<stdio.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netinet/in.h>

#include<stdlib.h>

#include<netdb.h>

#include<pthread.h>

void error(char *msg) //error msg function

{

	perror(msg);

	exit(1);

}

void *func(); //thread function

int newsockfd,n;

char buffer[256];

void main(int argc,char *argv[]) //command line argument to get port no

{

	int sockfd,cli_len,port_no;

	pthread_t tid; //thread declaration

	//char buffer[256];

	struct sockaddr_in serv_addr,cli_addr;

	if(argc<2)

	{

		fprintf(stderr,"error,no port");

		exit(1);

	}

	sockfd=socket(AF_INET,SOCK_STREAM,0); //socket creation

	if(sockfd<0)

	error("error opening socket");

	bzero((char*) &serv_addr,sizeof(serv_addr)); //initialization

	port_no=atoi(argv[1]);

	serv_addr.sin_family=AF_INET;

	serv_addr.sin_port=htons(port_no);

	serv_addr.sin_addr.s_addr=INADDR_ANY;

	if(bind(sockfd,(struct sockaddr*) &serv_addr,sizeof(serv_addr))<0)//binding with address

	error("error on binding");

	listen(sockfd,5); //listen the connection

	while(1)

	{

		cli_len=sizeof(cli_addr);

		newsockfd=accept(sockfd,(struct sockaddr*) &cli_addr,&cli_len);

		if(newsockfd<0)

		error("error in accept");

		pthread_create(&tid,NULL,func,NULL); //thread creation

	}

}

void *func()

{

	while(1)

	{

		n=read(newsockfd,buffer,255); //reading from buffer

		if(n<0)

			error("error in reading");

		printf("\nmsg %s",buffer);

		bzero(buffer,256);

		fgets(buffer,255,stdin);

		n=write(newsockfd,buffer,sizeof(buffer)); //writing into buffer
	
		if(n<0)

			error("error in writing");

	}

}


