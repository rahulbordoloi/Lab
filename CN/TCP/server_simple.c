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
		printf("\nSocket Creation Successful with ID: %d \n", x);
	}
	
	//host
	struct sockaddr_in src;
	src.sin_port = htons(6000);
	src.sin_addr.s_addr = INADDR_ANY;
	src.sin_family= AF_INET;
	
	//bind API
	int status = bind(x, (const struct sockaddr *)(&src), sizeof(src));
	if(status==-1)
    {
		printf("Bind Failure\n");
		exit(1);
	}
	else
    {
		printf("Socket %d is Successfully bound to Port %d\n", x, 6000);
	}

	//int cap=5;
    int l = listen(x, 1);                                                                    //listen() API, creates buffer
	if(l==-1)
	{
		printf("\nListen() Failed!\n");
	}
	else
	{
		printf("\nListen() Succesful!\n");
	}
	//while(cap>0)
	//{
		//cap--;
		struct sockaddr_in blank;  
		int t=sizeof(blank);
		int a = accept(x,(struct sockaddr*)(&blank),&t);                                    //accept() API, gives data Socket
		if(a==-1)
		{
			printf("\nAccept() Failed!\n");
		}
		else
		{
			printf("\nAccept() Succesful with Data Socket No: %d !\n",a);
		}
		while(1)                                                                         //live time machine
		{
			char sen[100];
			//="\nWelcome to Server\n";
			printf("\nEnter Message:\n");
			scanf("%s",sen);
			int s = send(a,sen,strlen(sen),0);                                             //send
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

			char rec[10]="";
			int r = recv(a,rec,sizeof(rec),0);                                              //receive
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
		}
		//cap++;
		//close(a);                                                                             //close() data socket
	//}

	int e = close(x);
	if(e==-1)
	{
		printf("\nServer Close() Failed!\n");
	}
	else
	{
		printf("\nServer Close() Succesful!\n");
	}
	return 0;
}






