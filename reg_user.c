#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "cpfapi.h"

int iUid=1000;

int uim_reg_usr( char *cBuffer ){
	FILE *fp;
	int i = 0,j = 0;
	char cName[100],cMailid[100],*str;	
	str=(char*)malloc(100*sizeof(char));
		while(cBuffer[i] != ',')
		cName[i++] = cBuffer[i];
	cName[i]='\0';
	i++;
	while(cBuffer[i] != '\0')
		cMailid[j++] = cBuffer[i++];
	cMailid[j]='\0';
	//printf("%s %s",cName,cMailid);
	fp = fopen("uid_table.csv","a+");
	if (fp == NULL){
		printf("Can't open a file");
		exit(0);
	}
	fprintf(fp,"%d %s %s\n",++iUid,cName,cMailid);
//	snprintf(str, 20, "%d", iUid);
//	printf("str : %s %d\n", str, strlen(str));
	fclose(fp);
	return iUid;
}

