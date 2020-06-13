#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
 #include <arpa/inet.h>


int main(int argc,char **argv)
{
      int flag=0;
	//creating socket
	int x = socket(AF_INET, SOCK_STREAM, 0);
	if(x == -1)
    {
		perror("Socket: ");
		exit(1);
	}
	else
    {
		printf("\nSocket Creation Successful\n");
	}

	//server details	
	
	struct sockaddr_in src,my_addr;
	src.sin_port = htons(atoi(argv[2]));
	inet_aton(argv[1],&src.sin_addr);
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
		perror("Connect: ");
	}
	else
	{
	         char myIP[16];
	         unsigned int myPort;
	         int len = sizeof(my_addr);
	          getsockname(x, (struct sockaddr *)(&my_addr), &len);
	          inet_ntop(AF_INET, &my_addr.sin_addr, myIP, sizeof(myIP));
	          myPort = ntohs(my_addr.sin_port);
	          printf("\nConnection Request Sent Successfully from  %s  and %d\n",myIP,myPort);
	}
	
	char sen[100];
            printf("\nEnter File Name to be Downloaded from Server: ");                                                  //send
	scanf("%s",sen);
	int s = send(x,sen,strlen(sen),0);
	if(s==-1)
	{
		perror("Send(): ");
	}
	
           FILE *f=fopen("recv.txt","w");
           char fm[100];
           int rec=recv(x,&fm,sizeof(fm),0);
           printf("\nReceived Data from Sever:%s\n",fm);
           do
              {   
                       rec=recv(x,fm,sizeof(fm),0);
                       if(strcmp(fm,"DNE")==0)
                       {
                          printf("%s",fm);
                          break;
                       }
                       if(strcmp(fm,"-1")==0)
                       {
                             printf("\nfile download complete\n");
                             break;
                        }
                        else if(rec==0)
                        {
                                 printf("\nFile Download Completed!\n");
                                 break;
                        }
                        else
                               {
                                    rec=recv(x,fm,sizeof(fm),0);
                                    printf("\nReceived Data of File:%s\n",fm);
                                    fwrite(fm,1,strlen(fm),f);
                                }  
               }while(rec>0);
             fclose(f);
             close(x);                                                                    //socket close
}
            
	           /*if(flag==0)
		{
		 printf("\nWaiting to Receive the Welcome Message...\n");
		 flag++;
		}*/
		/*char rec[100]="";
		int r = recv(x,rec,sizeof(rec),0);                                           //receive
		if(r==-1)
		{
			perror("Recv(): ");
		}
		else if(r==0)
		{
			printf("\nNo Bytes Received from Server!\n");
		}
		else
		 {
		           printf("\nReceived Message: %s\n",rec);
		           if(strcmp(rec,"exit")==0)
		           {
			
		           }
		}*/
	
	//int e = 
	
	/*if(e==-1)
	{
		printf("\nClient Close() Failedl!\n");
	}
	else
	{
		printf("\nClient Close() Succesful!\n");
	}
	return 0;*/
