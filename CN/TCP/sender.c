#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//creating socket
	int x = socket(AF_INET, SOCK_STREAM, 0);
	if(x == -1)
    {
		printf("\nSocket Creation Failed\n");
		exit(1);
	}
	else
    {
		printf("Socket Creation Successful with ID: %d \n", x);
	}

	//server details	
	struct sockaddr_in src;
	src.sin_port = htons(6000);
	src.sin_addr.s_addr = INADDR_ANY;
	src.sin_family= AF_INET;
	
	/*//bind API
	int status = bind(x, (const struct sockaddr *)(&src), sizeof(src));
	if(status==-1)
    {
		printf("Bind Failure\n");
		exit(1);
	}
	else
    {
		printf("Socket %d is Successfully bound to Port %d\n", x, 6000);
	}*/
	
	int c = connect(x,(const struct sockaddr*)(&src),sizeof(src));
    if(c==-1)
	{
		printf("\nConnect() Failed!\n");
	}
	else
	{
		printf("\nConnect() Succesful! with ID: %d \n", c);
	}
	while(1)                                                                         //live time machine
	{
		char rec[100]="";
		int r = recv(x,rec,sizeof(rec),0);                                           //receive
		/*if(r==-1)
		{
			printf("\nrecv() Failed!\n");
		}
		else
		{
			printf("\nrecv() Succesful!\n");
		}*/
		printf("\nReceived Message: %s\n",rec);
		if(strcmp(rec,"exit")==0)
		{
			break;
		}

		char sen[100];
		//="Thank You";
		printf("\nEnter Message:\n");                                                  //send
		scanf("%s",sen);
		int s = send(x,sen,strlen(sen),0);
		/*if(s==-1)
		{
			printf("\nSend() Failed!\n");
		}
		else
		{
			printf("\nSend() Succesful!\n");
		}*/
		if(strcmp(sen,"exit")==0)
		{
			break;
		}
	}
	
	int e = close(x);                                                                    //socket close
	if(e==-1)
	{
		printf("\nClient Close() Failedl!\n");
	}
	else
	{
		printf("\nClient Close() Succesful!\n");
	}
	return 0;
}





