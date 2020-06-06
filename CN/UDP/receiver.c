#include <sys/types.h>          
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <unistd.h>

int main()
{
 int x=socket(AF_INET, SOCK_DGRAM , 0);  
 if(x==-1)                                                  //socket()
 {
  printf("\nsocket creation failed\n");
  return 0;
 }
 else
 {
  printf("\nsocket creation succeded\n");
 
  struct sockaddr_in src;
  src.sin_port=htons(6000);                                         //host
  src.sin_addr.s_addr=INADDR_ANY;
  src.sin_family=AF_INET;
  
  int a=bind(x,(const struct sockaddr*)(&src),sizeof((src)));                 //bind()
  if(a==-1)
   printf("\nbind failure\n");
  else
   printf("\nbind success\n");
 }

  while(1)                                                               //live time machine
  {
    char rec[100]="";
    struct sockaddr_in blank;  
    int t=sizeof(blank);
    recvfrom(x,rec,sizeof(rec),0,(struct sockaddr*)(&blank),&t);                //recvfrom()
    printf("\nReceived Message : %s \n",rec);
    if(strcmp(rec,"bye")==0)
    {
      break;		
		}
    /*int h;
    if(h==-1)
      printf("\nRecvfrom() Failed.\n");
    else
      printf("\nRecvfrom() Successful.\n"); */
    
    char sen[100]="";
    printf("\nEnter Message :");
    scanf("%s",sen);

    struct sockaddr_in dst;
    dst.sin_port=htons(5000);                                                 //sender
    dst.sin_addr.s_addr=INADDR_ANY;
    dst.sin_family=AF_INET;
    sendto(x,sen,strlen(sen),0,(struct sockaddr*)(&dst),sizeof((dst)));                        //send to()
    if(strcmp(rec,"bye")==0)
    {
      break;		
		}
    /*if(y==-1)
       printf("\nSendto() Failed.\n");
    else
       printf("\nSendto() Successful.\n");*/
    
  }


    //int cs=
    close(x);                              //close()
    /*if(cs==0)
       printf("\nClose() Successful\n");
    else
       printf("\nClose() Unsuccessful\n");*/
   return 0;
}                        





