#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include<sys/wait.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
 int sid,bid,i,n,rid,j=0;
 int pid;
 char msg[30];
 pid=fork();
 //wait(NULL);
 if(pid==0)
 {
  struct sockaddr_in sin,cin;
  sid=socket(AF_INET,SOCK_DGRAM,0);
  if(sid==-1)
  {
   perror("\n Error in socket connection..\n");
   exit(0);
  }
  printf("\n Client 1 : Socket created successfully ..\n");
  sin.sin_family=AF_INET;
  sin.sin_port=htons(8002);
  sin.sin_addr.s_addr=htonl(INADDR_ANY);
  bid=bind(sid,(struct sockaddr*)&sin,sizeof(sin));
  if(bid==-1)
  {
   perror("\n Error in binding..\n");
   exit(0);
  }
  printf("\n Client 1 : Binded successfully..\n");
  n=sizeof(cin);
  while(1)
  {
   char msg_c1[20];
   rid=recvfrom(sid,msg,sizeof(msg),0,(struct sockaddr*)&cin,&n);
   if(rid==-1)
   {
    perror("\n Error in receiving..\n");
    exit(0);
   }
   printf("\n From Client 1 : %s\n",msg);
   printf("\n To client 1 : ");
   scanf("%s",msg_c1);
   sendto(sid,msg_c1,50,0,(struct sockaddr*)&cin,sizeof(cin));
   if(strcmp(msg,"bye")==0 || strcmp(msg_c1,"bye")==0 )
           break;
  }
 }
 else
 {
  struct sockaddr_in sin,cin;
  sid=socket(AF_INET,SOCK_DGRAM,0);
  if(sid==-1)
  {
   perror("\n Error in socket connection..\n");
   exit(0);
  }
  printf("\n Client 2 : Socket created successfully..\n");
  sin.sin_family=AF_INET;
  sin.sin_port=htons(8502);
  sin.sin_addr.s_addr=htonl(INADDR_ANY);
  bid=bind(sid,(struct sockaddr*)&sin,sizeof(sin));
  if(bid==-1)
  {
   perror("\n Error in binding..\n");
   exit(0);
  }
  printf("\n Client 2 : Binded successfully..\n");
  n=sizeof(cin);
  while(1)
  {
   char msg_c1[20];
   rid=recvfrom(sid,msg,sizeof(msg),0,(struct sockaddr*)&cin,&n);
   if(rid==-1)
   {
    perror("\n Error in receiving..\n");
    exit(0);
   }
   printf("\n From Client 2 : %s\n",msg);
   printf("\n To client 2 : ");
   scanf("%s",msg_c1);
   sendto(sid,msg_c1,50,0,(struct sockaddr*)&cin,sizeof(cin));
   if(strcmp(msg,"bye")==0)
           break;
  }
 }
 printf("\n Connection terminated for client..\n");
 close(sid);
}
