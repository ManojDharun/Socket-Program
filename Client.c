#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
 char msg_snd[100],msg_rec[100];
 int sid,bid,i,n,rid;
 struct sockaddr_in sin,cin;
 sid=socket(AF_INET,SOCK_DGRAM,0);
 if(sid==-1)
 {
  perror("\n Error in socket connection..\n");
  exit(0);
 }
 printf("\n Socket created successfully..\n");
 sin.sin_family=AF_INET;
 sin.sin_port=htons(8002);
 sin.sin_addr.s_addr=htonl(INADDR_ANY);
 n=sizeof(cin);
 while(1)
 {
  printf("\n Client 1 :");
  scanf("%[^\n]%*c",msg_snd);
  sendto(sid,msg_snd,50,0,(struct sockaddr*)&sin,sizeof(sin));
  recvfrom(sid,msg_rec,50,0,(struct sockaddr*)&cin,&n);
  printf("\n From server : %s",msg_rec);
  if(strcmp(msg_rec,"bye")==0 || strcmp(msg_snd,"bye")==0 )
   break;
 }
 printf("\n Connection terminated..\n");
 close(sid);
}
