#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main( )
{
	char cInput_Buffer[150],cCommand[100],cInput_Fields[150];
	int iOpt=0,iLength=0,i=0,iCommand_Length=0,j=0;
	printf("\n1.Register user [REG_USR:name,mailid]\n2.Register service [REG_SVC:UID,service_name,type of service]\n3.get service list [GET_SVC_LIST:UID,category(all/provider/type of service)] \n4.SUBSCRIBE\n5.START_SESSION\n6.END_SESSION\nEnter your option 1 to 6\n");
		fgets(cInput_Buffer,150,stdin);
		printf("%s\n",cInput_Buffer);
		iLength=strlen(cInput_Buffer);
		while(cInput_Buffer[iCommand_Length]!=':')
		{
			iCommand_Length++;
		}
	/*	for(i=0;i<iCommand_Length;i++)
		{
			cCommand[j]=cInput_Buffer[i];
			printf("%c",cCommand[j]);
			j++;
		}
		cCommand[++j]='\0';
		j=0;	*/
	        printf("%d",iCommand_Length);
		strncpy(cCommand,cInput_Buffer,iCommand_Length);
		printf("\n%s",cCommand);

		for(i=iCommand_Length+1;cInput_Buffer[i]!='\0';i++)
		{
			cInput_Fields[j]=cInput_Buffer[i];
			printf("\n%c",cInput_Fields[j]);
			j++;
			
			cInput_Buffer[++j]='\0';
		}
	//	for(i=0;cCommand[i]!='\0';i++)
	//	printf("\n%c",cCommand[i]);
}
