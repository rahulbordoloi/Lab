#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <errno.h>
#include <arpa/inet.h>

#define f(i,a,b) for(i=a;i<b;i++)

int main(int argc,char **argv)
{
	int conn[5],z=0;
	//creating socket
	int x = socket(AF_INET, SOCK_STREAM, 0);
	if(x == -1)
    {
		perror("socket :");
		exit(1);
	}
	else
    {
		printf("\nSocket Creation Successful\n");
	}
	
	struct sockaddr_in src;
	src.sin_port = htons(atoi(argv[1]));
	src.sin_addr.s_addr = inet_addr("10.2.252.183");
	src.sin_family= AF_INET;
	
	//bind API
	int status = bind(x, (const struct sockaddr *)(&src), sizeof(src));
	if(status==-1)
    {
		perror("bind:");
		exit(1);
	}
	else
    {
		printf("Binded the created Socket with the process successfully\n");
	}

    int cap=3;
	int l = listen(x, 3);                                                                    //listen() API, creates buffer
	if(l==-1)
	{
		perror("listen:");
	}
	else
	{
		printf("\nwaiting for connection request from clients...\n");
	}
	while(cap>0)
	{
		cap--;
		struct sockaddr_in blank;  
		int t=sizeof(blank);
		int a = accept(x,(struct sockaddr*)(&blank),&t);                                    //accept() API, gives data Socket
		if(a==-1)
		{
			perror("accept:");
		}
		else
		{
		    conn[z++]=a;
			char myIP[20];
		    unsigned int myPort;
		    int t=sizeof(blank);
		    getpeername(x,(struct sockaddr*)(&blank),&t);
		    inet_ntop(AF_INET,&blank.sin_addr,myIP,sizeof(myIP));
		    myPort=ntohs(blank.sin_port);
			printf("\nConnected to the client  %s      %d \n",myIP,myPort);
		}
		
		char sen[100]="welcome to server";
			printf("\nSending the welcome message to the client\n");
			
			int s = send(a,sen,strlen(sen),0);   
			                                          //send
			if(s==-1)
			{
				perror("send:");
			}
			else
			{
				printf("\n");
			}
		
		
		
		
			while(1)                                                                         //live time machine
		{
			
			printf("waiting to receive message from client\n");

			char rec[10]="";
			int r = recv(a,rec,sizeof(rec),0);                                              //receive
			if(r==-1)
			{
				perror("recv:");
			}
			else
			{
				printf("\nreceived message:%s\n",rec);
			}
			
			if(strcmp(rec,"bye")==0)
			{
				break;
			}
		}
		cap++;
		close(a);
		}
		
		close(x);                                                                             //close() data socket
	    int i;
		f(i,0,z)
		{
			printf("%d",conn[i]);
		}
	
	
	

		}
		
		
		
