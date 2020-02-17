#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	char *buffer,*buffer1,*word,*line,*a;
	buffer=(char *)malloc(1024*sizeof(char));
	word=(char *)malloc(1024*sizeof(char));
	a= (char *)malloc(1024*sizeof(char));
	line=(char *)malloc(1024*sizeof(char));
	buffer1=(char *)malloc(1024*sizeof(char));

	memset(buffer,0,sizeof(buffer));
	memset(line,0,sizeof(line));
	memset(word,0,sizeof(word));
	memset(buffer1,0,sizeof(buffer1));

	fp=fopen("text.txt","r");

	while(fgets(buffer,1024,fp)!=NULL){
		for(int i=0;i<strlen(buffer);i++){
			line=buffer;
			printf("line:%s\n",line);
			line[strlen(line)]='\0';
			if((word=strchr(line,' ' ))!=NULL){
				printf("word:%s\n",word);
				strncpy(buffer1,buffer,strlen(buffer)-strlen(word));
				printf("buffer1:%s\n",buffer1);
				++word;
				//intf("word:%s\n",word);
				buffer=word;
				//printf("buffer:%s\n",buffer);
		
			}	
		}

	}

}
